/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save player
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <engine.h>
#include <envdata.h>
#include <file_utils.h>
#include <hnep/nstring.h>

PRIVATE void save_player_progress(player_t *player, xml_balise_t *bprogress, \
xml_balise_t *bquest_id)
{
    char *level = int_to_str(player->level);
    char *xp = int_to_str(player->xp);
    char *quest_id = int_to_str(player->quest_id);

    xml_add_attribute(bprogress, "level", level);
    xml_add_attribute(bprogress, "xp", xp);
    xml_set_content(bquest_id, quest_id);
    free(level);
    free(xp);
    free(quest_id);
}

PRIVATE xml_balise_t *convert_player_to_xml(player_t *player)
{
    xml_balise_t *save = xml_add_balise(NULL, "save");
    xml_balise_t *progress = xml_add_balise(save, "progress");
    xml_balise_t *achievements = xml_add_balise(save, "achievements");
    xml_balise_t *quests = xml_add_balise(save, "quests");
    xml_balise_t *quest_id = xml_add_balise(save, "quest_id");

    save_attributes_player(player, save);
    save_pos_player(player, save);
    save_player_pickitems(player, save);
    save_player_inventory(player, save);
    save_player_skills(player, save);
    save_player_progress(player, progress, quest_id);
    xml_set_content(achievements, player->achievements);
    xml_set_content(quests, player->quests);
    return (save);
}

PRIVATE void save_player_xml(player_t *player)
{
    xml_balise_t *xml;
    char *path;
    char *output;

    if (player == NULL)
        return;
    xml = convert_player_to_xml(player);
    if (xml == NULL)
        return;
    path = string_format("saves/%s.xml", player->save_name);
    output = xml_serialize(xml);
    if (output == NULL || path == NULL)
        return;
    write_file(path, output);
    xml_free(xml);
    free(output);
    free(path);
}

PRIVATE void save_player(player_t *player)
{
    if (player == NULL || player->save_name == NULL)
        return;
    player->ingame_time += 3;
    save_player_xml(player);
}

void save_player_clock(player_t *player)
{
    sfClock *clock;
    sfInt64 time;
    sfThread *th;

    if (player == NULL || player->last_save == NULL)
        return;
    clock = player->last_save;
    time = sfClock_getElapsedTime(clock).microseconds;
    if (time < 3000000)
        return;
    th = sfThread_create((void (*)(void *)) &save_player, player);
    sfThread_launch(th);
    sfClock_restart(clock);
}