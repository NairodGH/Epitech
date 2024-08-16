#include "includes.h"

typedef struct {
    model_e type;
    const char *path;
    Vector3 rotation;
    Vector3 scale;
} relation_t;

static const relation_t relation[] = {
    {MODEL_BATARANG, "resources/batarang/Batarang.obj", {0, 0, 0}, {1, 1, 1}},
    {MODEL_DORION, "resources/dorion/Dorion.glb", {90, 0, 270}, {0.6, 0.6, 0.6}},
    {MODEL_DORION2, "resources/dorion/Dorion2.glb", {0, 90, 0}, {1.3, 1.3, 1.3}},
    {MODEL_AMMO_BOX, "resources/ammo_box.glb", {270, 0, 0}, {0.03, 0.1, 0.03}},
    {MODEL_DEADPOOL, "resources/deadpool/Deadpool.glb", {90, 180, 0}, {0.65, 0.65, 0.65}},
    {MODEL_MIDORIYA, "resources/midoriya/Midoriya.glb", {0, 180, 0}, {0.013, 0.013, 0.013}},
    {MODEL_BALD_MIDORIYA, "resources/midoriya/bald_Midoriya.glb", {0, 180, 0}, {0.013, 0.013, 0.013}},
    {MODEL_AMOGUS, "resources/amogus.glb", {0, 180, 0}, {0.7, 0.7, 0.7}},
    {MODEL_KNIGHT, "resources/evilKnight.glb", {0, 180, 0}, {1, 1, 1}},
    {MODEL_TRACTOR, "resources/tractor.glb", {0, 90, 90}, {0.7, 0.7, 0.7}},
};

Model *getModel(list_t *list, model_e type)
{
    node_t *node = NULL;
    model_t *model = NULL;

    foreach(list->head, node) {
        model = (model_t *)node->data;
        if (model->type == type) {
            return &(model->model);
        }
    }
    return NULL;
}

Model getModelbyModel_t(list_t *list, model_t *model)
{
    node_t *node = NULL;
    model_t *tmp = NULL;

    foreach(list->head, node) {
        tmp = (model_t *)node->data;
        if (tmp == model) {
            return tmp->model;
        }
    }
    return (Model){0};
}

model_e getModelType(list_t *list, model_t *model)
{
    node_t *node = NULL;
    model_t *tmp = NULL;

    foreach(list->head, node) {
        tmp = (model_t *)node->data;
        if (tmp == model) {
            return tmp->type;
        }
    }
    return 0;
}

bool isModel(node_t *node, model_e type)
{
    model_t *model = (model_t *)node->data;

    if (model->type == type) {
        return true;
    }
    return false;
}

void initModels(game_t *game)
{
    model_t *model = NULL;

    game->model = list_create();
    for (int i = 0; i < sizeof(relation) / sizeof(relation_t); i++) {
        model = calloc(1, sizeof(model_t));
        model->type = relation[i].type;
        model->model = LoadModel(relation[i].path);
        model->model.transform = MatrixMultiply(model->model.transform, MatrixRotateX(relation[i].rotation.x * DEG2RAD));
        model->model.transform = MatrixMultiply(model->model.transform, MatrixRotateY(relation[i].rotation.y * DEG2RAD));
        model->model.transform = MatrixMultiply(model->model.transform, MatrixRotateZ(relation[i].rotation.z * DEG2RAD));
        model->model.transform = MatrixMultiply(model->model.transform, MatrixScale(relation[i].scale.x, relation[i].scale.y, relation[i].scale.z));
        list_push_data(game->model, model);
    }
}
