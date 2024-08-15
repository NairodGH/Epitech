##
## EPITECH PROJECT, 2021
## Base
## File description:
## Main Makefile
##

PATH_BUILD		=	./build
PATH_SRC		=	./src
PATH_LIBS		=	./lib/

SRC				=	$(PATH_SRC)/csfml/buttons/create_button.c\
					$(PATH_SRC)/csfml/buttons/update_button.c\
					$(PATH_SRC)/csfml/buttons/destroy_button.c\
					$(PATH_SRC)/csfml/buttons/destroy_buttons.c\
					$(PATH_SRC)/csfml/buttons/is_button_clicked.c\
					$(PATH_SRC)/csfml/buttons/get_button_path.c\
					$(PATH_SRC)/csfml/buttons/register_button.c\
					$(PATH_SRC)/csfml/buttons/draw_button.c\
					$(PATH_SRC)/csfml/buttons/draw_button_tooltips.c\
					$(PATH_SRC)/csfml/buttons/draw_buttons.c\
					$(PATH_SRC)/csfml/buttons/get_button_by_id.c\
					$(PATH_SRC)/csfml/buttons/get_button_color.c\
					$(PATH_SRC)/csfml/buttons/get_button_pos.c\
					$(PATH_SRC)/csfml/buttons/get_button_rect.c\
					$(PATH_SRC)/csfml/buttons/get_button_size.c\
					$(PATH_SRC)/csfml/buttons/set_button_path.c\
					$(PATH_SRC)/csfml/buttons/set_button_pos.c\
					$(PATH_SRC)/csfml/buttons/set_button_rect.c\
					$(PATH_SRC)/csfml/buttons/set_button_size.c\
					$(PATH_SRC)/csfml/buttons/set_button_visible.c\
					$(PATH_SRC)/csfml/buttons/set_button_hovered.c\
					$(PATH_SRC)/csfml/buttons/set_button_id.c\
					$(PATH_SRC)/csfml/buttons/set_button_clicked.c\
					$(PATH_SRC)/csfml/buttons/set_button_color.c\
					$(PATH_SRC)/csfml/buttons/set_button_events.c\
					$(PATH_SRC)/csfml/engine/close_engine.c\
					$(PATH_SRC)/csfml/engine/create_engine.c\
					$(PATH_SRC)/csfml/engine/destroy_engine.c\
					$(PATH_SRC)/csfml/engine/handle_builtin_events.c\
					$(PATH_SRC)/csfml/engine/handle_button_click.c\
					$(PATH_SRC)/csfml/engine/handle_object_click.c\
					$(PATH_SRC)/csfml/engine/handle_object_hover.c\
					$(PATH_SRC)/csfml/engine/handle_text_click.c\
					$(PATH_SRC)/csfml/engine/poll_events.c\
					$(PATH_SRC)/csfml/engine/start_engine.c\
					$(PATH_SRC)/csfml/engine/update_game_loop.c\
					$(PATH_SRC)/csfml/math/is_in_square.c\
					$(PATH_SRC)/csfml/objects/center_obj_x.c\
					$(PATH_SRC)/csfml/objects/center_obj_xy.c\
					$(PATH_SRC)/csfml/objects/center_obj_y.c\
					$(PATH_SRC)/csfml/objects/create_object.c\
					$(PATH_SRC)/csfml/objects/create_shader.c\
					$(PATH_SRC)/csfml/objects/destroy_object.c\
					$(PATH_SRC)/csfml/objects/destroy_objects.c\
					$(PATH_SRC)/csfml/objects/draw_object.c\
					$(PATH_SRC)/csfml/objects/draw_object_shader.c\
					$(PATH_SRC)/csfml/objects/draw_objects.c\
					$(PATH_SRC)/csfml/objects/draw_objects_shaders.c\
					$(PATH_SRC)/csfml/objects/duplicate_object.c\
					$(PATH_SRC)/csfml/objects/get_obj_asset.c\
					$(PATH_SRC)/csfml/objects/get_obj_by_id.c\
					$(PATH_SRC)/csfml/objects/get_obj_center.c\
					$(PATH_SRC)/csfml/objects/get_obj_color.c\
					$(PATH_SRC)/csfml/objects/get_obj_pos.c\
					$(PATH_SRC)/csfml/objects/get_obj_rect.c\
					$(PATH_SRC)/csfml/objects/get_obj_sprite.c\
					$(PATH_SRC)/csfml/objects/get_obj_texture.c\
					$(PATH_SRC)/csfml/objects/get_obj_type.c\
					$(PATH_SRC)/csfml/objects/get_obj_renderstates.c\
					$(PATH_SRC)/csfml/objects/get_obj_shader.c\
					$(PATH_SRC)/csfml/objects/is_obj_clicked.c\
					$(PATH_SRC)/csfml/objects/is_obj_visible.c\
					$(PATH_SRC)/csfml/objects/register_object.c\
					$(PATH_SRC)/csfml/objects/set_obj_asset.c\
					$(PATH_SRC)/csfml/objects/set_obj_child.c\
					$(PATH_SRC)/csfml/objects/set_obj_color.c\
					$(PATH_SRC)/csfml/objects/set_obj_events.c\
					$(PATH_SRC)/csfml/objects/set_obj_pos.c\
					$(PATH_SRC)/csfml/objects/set_obj_rect.c\
					$(PATH_SRC)/csfml/objects/set_obj_renderstates.c\
					$(PATH_SRC)/csfml/objects/set_obj_shader.c\
					$(PATH_SRC)/csfml/objects/set_obj_tooltip.c\
					$(PATH_SRC)/csfml/objects/set_obj_type.c\
					$(PATH_SRC)/csfml/objects/set_obj_visibility.c\
					$(PATH_SRC)/csfml/panels/call_panel_events.c\
					$(PATH_SRC)/csfml/panels/close_panel.c\
					$(PATH_SRC)/csfml/panels/close_panel_by_id.c\
					$(PATH_SRC)/csfml/panels/create_panel.c\
					$(PATH_SRC)/csfml/panels/destroy_panel.c\
					$(PATH_SRC)/csfml/panels/destroy_panels.c\
					$(PATH_SRC)/csfml/panels/draw_panel.c\
					$(PATH_SRC)/csfml/panels/draw_panels.c\
					$(PATH_SRC)/csfml/panels/get_panel_by_id.c\
					$(PATH_SRC)/csfml/panels/hide_panel.c\
					$(PATH_SRC)/csfml/panels/is_panel_visible.c\
					$(PATH_SRC)/csfml/panels/register_panel.c\
					$(PATH_SRC)/csfml/panels/set_panel_bgsound.c\
					$(PATH_SRC)/csfml/panels/set_panel_events.c\
					$(PATH_SRC)/csfml/panels/set_panel_initializer.c\
					$(PATH_SRC)/csfml/panels/set_panel_updater.c\
					$(PATH_SRC)/csfml/panels/set_panel_visibility.c\
					$(PATH_SRC)/csfml/panels/show_panel.c\
					$(PATH_SRC)/csfml/panels/show_panel_by_id.c\
					$(PATH_SRC)/csfml/panels/tick_panels.c\
					$(PATH_SRC)/csfml/sounds/create_sound.c\
					$(PATH_SRC)/csfml/sounds/update_sound.c\
					$(PATH_SRC)/csfml/sounds/destroy_sound.c\
					$(PATH_SRC)/csfml/sounds/gc_sounds.c\
					$(PATH_SRC)/csfml/sounds/get_sound_path.c\
					$(PATH_SRC)/csfml/sounds/get_sound_status.c\
					$(PATH_SRC)/csfml/sounds/get_sound_volume.c\
					$(PATH_SRC)/csfml/sounds/get_sound_pitch.c\
					$(PATH_SRC)/csfml/sounds/set_sound_path.c\
					$(PATH_SRC)/csfml/sounds/play_seffect.c\
					$(PATH_SRC)/csfml/sounds/play_sound.c\
					$(PATH_SRC)/csfml/sounds/register_sound.c\
					$(PATH_SRC)/csfml/sounds/pause_sound.c\
					$(PATH_SRC)/csfml/sounds/stop_sound.c\
					$(PATH_SRC)/csfml/sounds/set_sound_loop.c\
					$(PATH_SRC)/csfml/sounds/set_sound_volume.c\
					$(PATH_SRC)/csfml/sounds/set_sound_pitch.c\
					$(PATH_SRC)/csfml/texts/center_text_x.c\
					$(PATH_SRC)/csfml/texts/center_text_xy.c\
					$(PATH_SRC)/csfml/texts/center_text_y.c\
					$(PATH_SRC)/csfml/texts/create_text.c\
					$(PATH_SRC)/csfml/texts/destroy_text.c\
					$(PATH_SRC)/csfml/texts/destroy_texts.c\
					$(PATH_SRC)/csfml/texts/draw_text.c\
					$(PATH_SRC)/csfml/texts/draw_texts.c\
					$(PATH_SRC)/csfml/texts/get_text_by_type.c\
					$(PATH_SRC)/csfml/texts/get_text_color.c\
					$(PATH_SRC)/csfml/texts/get_text_content.c\
					$(PATH_SRC)/csfml/texts/get_text_endpos.c\
					$(PATH_SRC)/csfml/texts/get_text_font.c\
					$(PATH_SRC)/csfml/texts/get_text_pos.c\
					$(PATH_SRC)/csfml/texts/get_text_size.c\
					$(PATH_SRC)/csfml/texts/get_text_state.c\
					$(PATH_SRC)/csfml/texts/get_text_type.c\
					$(PATH_SRC)/csfml/texts/is_text_clicked.c\
					$(PATH_SRC)/csfml/texts/is_text_visible.c\
					$(PATH_SRC)/csfml/texts/register_text.c\
					$(PATH_SRC)/csfml/texts/set_text_color.c\
					$(PATH_SRC)/csfml/texts/set_text_content.c\
					$(PATH_SRC)/csfml/texts/set_text_events.c\
					$(PATH_SRC)/csfml/texts/set_text_font.c\
					$(PATH_SRC)/csfml/texts/set_text_pos.c\
					$(PATH_SRC)/csfml/texts/set_text_size.c\
					$(PATH_SRC)/csfml/texts/set_text_state.c\
					$(PATH_SRC)/csfml/texts/set_text_type.c\
					$(PATH_SRC)/csfml/texts/set_text_visibility.c\
					$(PATH_SRC)/csfml/texts/update_text.c\
					$(PATH_SRC)/csfml/tooltip/display_tooltip.c\
					$(PATH_SRC)/csfml/tooltip/get_tooltip_by_id.c\
					$(PATH_SRC)/csfml/tooltip/get_tooltip_size.c\
					$(PATH_SRC)/csfml/tooltip/get_tooltip_pos.c\
					$(PATH_SRC)/csfml/tooltip/register_tooltip.c\
					$(PATH_SRC)/csfml/tooltip/set_tooltip.c\
					$(PATH_SRC)/csfml/tooltip/set_tooltip_id.c\
					$(PATH_SRC)/csfml/window/create_window.c\
					$(PATH_SRC)/csfml/window/center_window.c\
					$(PATH_SRC)/csfml/window/destroy_window.c\
					$(PATH_SRC)/csfml/window/get_window.c\
					$(PATH_SRC)/csfml/window/get_window_scale.c\
					$(PATH_SRC)/csfml/window/get_window_size.c\
					$(PATH_SRC)/csfml/window/has_display_env.c\
					$(PATH_SRC)/csfml/window/set_window_framerate.c\
					\
					$(PATH_SRC)/achievements/already_finished_achievement.c \
					$(PATH_SRC)/achievements/display_achievements.c \
					$(PATH_SRC)/achievements/finish_achievement.c \
					$(PATH_SRC)/achievements/get_achievement_type.c \
					$(PATH_SRC)/achievements/get_npc_achievement.c \
					$(PATH_SRC)/achievements/parse_achievements.c \
					$(PATH_SRC)/achievements/register_achievement_objects.c \
					$(PATH_SRC)/achievements/save_achievement.c \
					\
					$(PATH_SRC)/args/create_arg_list.c \
					$(PATH_SRC)/args/get_arg.c \
					$(PATH_SRC)/args/has_arg.c \
					\
					$(PATH_SRC)/draw/draw_map.c \
					$(PATH_SRC)/draw/get_mrelative.c \
					\
					$(PATH_SRC)/entities/display_entities.c \
					$(PATH_SRC)/entities/display_quest_start_card.c \
					$(PATH_SRC)/entities/get_entity_distance.c \
					$(PATH_SRC)/entities/parse_entities.c \
					$(PATH_SRC)/entities/parse_entity_attributes.c \
					$(PATH_SRC)/entities/parse_fight.c \
					$(PATH_SRC)/entities/parse_pos.c \
					$(PATH_SRC)/entities/parse_quest.c \
					$(PATH_SRC)/entities/parse_quest_reward.c \
					$(PATH_SRC)/entities/parse_rect.c \
					$(PATH_SRC)/entities/prepare_entity_object.c \
					$(PATH_SRC)/entities/update_entity_position.c \
					\
					$(PATH_SRC)/env/convert_env_to_str.c \
					$(PATH_SRC)/env/create_env_key.c \
					$(PATH_SRC)/env/create_env_list.c \
					$(PATH_SRC)/env/env_exists.c \
					$(PATH_SRC)/env/get_env_from_file.c \
					$(PATH_SRC)/env/get_env_len.c \
					$(PATH_SRC)/env/get_env_value.c \
					$(PATH_SRC)/env/get_env_valuedef.c \
					$(PATH_SRC)/env/parse_env.c \
					$(PATH_SRC)/env/save_env_array.c \
					$(PATH_SRC)/env/update_env.c \
					\
					$(PATH_SRC)/fight/fight_turn_ia.c \
					$(PATH_SRC)/fight/start_fight.c \
					\
					$(PATH_SRC)/fps/start_fps.c \
					\
					$(PATH_SRC)/init/grid/grid_create.c \
					$(PATH_SRC)/init/grid/grid_position.c \
					\
					$(PATH_SRC)/init/map/layer_create.c \
					$(PATH_SRC)/init/map/layer_fill.c \
					$(PATH_SRC)/init/map/layer_free.c \
					$(PATH_SRC)/init/map/layer_set.c \
					$(PATH_SRC)/init/map/map_create.c \
					$(PATH_SRC)/init/map/map_fill.c \
					$(PATH_SRC)/init/map/map_free.c \
					\
					$(PATH_SRC)/init/player/init_player.c \
					\
					$(PATH_SRC)/init/tiled/tiled_free.c \
					$(PATH_SRC)/init/tiled/tiled_layer.c \
					$(PATH_SRC)/init/tiled/tiled_parser.c \
					$(PATH_SRC)/init/tiled/tiled_tileset.c \
					\
					$(PATH_SRC)/init/tileset/tile_get.c \
					$(PATH_SRC)/init/tileset/tileset_create.c \
					$(PATH_SRC)/init/tileset/tileset_free.c \
					$(PATH_SRC)/init/tileset/tileset_get.c \
					$(PATH_SRC)/init/tileset/tileset_register.c \
					\
					$(PATH_SRC)/inventory/items/get_item_from_id.c \
					$(PATH_SRC)/inventory/items/get_item_from_tile_id.c \
					$(PATH_SRC)/inventory/items/parse_item_consumable.c \
					$(PATH_SRC)/inventory/items/parse_items.c \
					$(PATH_SRC)/inventory/add_inventory_item.c \
					$(PATH_SRC)/inventory/consume_itemstack.c \
					$(PATH_SRC)/inventory/create_itemstack.c \
					$(PATH_SRC)/inventory/debug_inventory.c \
					$(PATH_SRC)/inventory/get_available_itemstack.c \
					$(PATH_SRC)/inventory/get_inventory.c \
					$(PATH_SRC)/inventory/get_inventory_count.c \
					$(PATH_SRC)/inventory/get_itemstack.c \
					$(PATH_SRC)/inventory/get_itemstack_from_tileid.c \
					$(PATH_SRC)/inventory/remove_inventory_item.c \
					$(PATH_SRC)/inventory/remove_itemstack.c \
					\
					$(PATH_SRC)/panels/animation/handle_panel_anim.c \
					$(PATH_SRC)/panels/animation/init_panel_anim.c \
					\
					$(PATH_SRC)/panels/credits/init_panel_credits.c \
					$(PATH_SRC)/panels/credits/scroll_credits.c \
					$(PATH_SRC)/panels/credits/credits_events.c \
					\
					$(PATH_SRC)/panels/custom_player/handle_cusplayer_buttons.c \
					$(PATH_SRC)/panels/custom_player/init_panel_cusplayer.c \
					$(PATH_SRC)/panels/custom_player/on_cusplayer_render.c \
					$(PATH_SRC)/panels/custom_player/player_assets.c \
					\
					$(PATH_SRC)/panels/end/init_end_credits.c \
					$(PATH_SRC)/panels/end/init_end_home.c \
					$(PATH_SRC)/panels/end/init_panel_end.c \
					\
					$(PATH_SRC)/panels/exit/init_buttons_exit.c \
					$(PATH_SRC)/panels/exit/init_panel_exit.c \
					\
					$(PATH_SRC)/panels/game/achievements/create_achievement_card.c \
					$(PATH_SRC)/panels/game/achievements/init_panel_achievements.c \
					$(PATH_SRC)/panels/game/achievements/panel_achievement_events.c \
					\
					$(PATH_SRC)/panels/game/actionbar/init_action_bar.c \
					$(PATH_SRC)/panels/game/actionbar/set_action_bar.c \
					$(PATH_SRC)/panels/game/actionbar/update_action_bar.c \
					\
					$(PATH_SRC)/panels/game/cutscene/skip_cutscene.c \
					$(PATH_SRC)/panels/game/cutscene/end_cutscene.c \
					$(PATH_SRC)/panels/game/cutscene/handle_cutscene.c \
					$(PATH_SRC)/panels/game/cutscene/is_cutscene_started.c \
					$(PATH_SRC)/panels/game/cutscene/parse_cutscene.c \
					$(PATH_SRC)/panels/game/cutscene/start_cutscene.c \
					\
					$(PATH_SRC)/panels/game/entity/display_npc_panel.c \
					$(PATH_SRC)/panels/game/entity/get_discuss_chars.c \
					$(PATH_SRC)/panels/game/entity/get_nearest_npc.c \
					$(PATH_SRC)/panels/game/entity/get_itr_char.c \
					$(PATH_SRC)/panels/game/entity/get_quest_chars.c \
					$(PATH_SRC)/panels/game/entity/init_npc_panel.c \
					$(PATH_SRC)/panels/game/effect/init_snow_panel.c \
					$(PATH_SRC)/panels/game/effect/init_rain_panel.c \
					$(PATH_SRC)/panels/game/effect/init_fog_panel.c \
					$(PATH_SRC)/panels/game/entity/npc_discuss.c \
					$(PATH_SRC)/panels/game/entity/npc_events.c \
					$(PATH_SRC)/panels/game/entity/npc_quest.c \
					$(PATH_SRC)/panels/game/entity/npc_quest_end.c \
					$(PATH_SRC)/panels/game/entity/npc_quest_rewards.c \
					\
					$(PATH_SRC)/panels/game/inventory/gui/init_panel_inventory.c \
					$(PATH_SRC)/panels/game/inventory/gui/inventory_events.c \
					$(PATH_SRC)/panels/game/inventory/gui/inventory_pagnation.c \
					$(PATH_SRC)/panels/game/inventory/gui/inventory_render.c \
					$(PATH_SRC)/panels/game/inventory/gui/panel_inventory_events.c \
					$(PATH_SRC)/panels/game/inventory/gui/register_panel_assets.c \
					$(PATH_SRC)/panels/game/inventory/gui/render_inventory_items.c \
					$(PATH_SRC)/panels/game/inventory/hud/draw_inventory_bar_items.c \
					$(PATH_SRC)/panels/game/inventory/hud/draw_item_tooltip.c \
					$(PATH_SRC)/panels/game/inventory/hud/init_inventory_bar.c \
					$(PATH_SRC)/panels/game/inventory/hud/on_item_click.c \
					\
					$(PATH_SRC)/panels/game/pause/handle_buttons_pause.c \
					$(PATH_SRC)/panels/game/pause/init_buttons_pause.c \
					$(PATH_SRC)/panels/game/pause/init_panel_pause.c \
					\
					$(PATH_SRC)/panels/game/pickup/add_pick_item.c \
					$(PATH_SRC)/panels/game/pickup/display_pickup_panel.c \
					$(PATH_SRC)/panels/game/pickup/get_item_nearest.c \
					$(PATH_SRC)/panels/game/pickup/handle_item_pick.c \
					$(PATH_SRC)/panels/game/pickup/init_pickup_panel.c \
					$(PATH_SRC)/panels/game/pickup/remove_pickitems.c \
					\
					$(PATH_SRC)/panels/game/player/get_player.c \
					$(PATH_SRC)/panels/game/player/get_player_tile.c \
					$(PATH_SRC)/panels/game/player/handle_health.c \
					$(PATH_SRC)/panels/game/player/is_movement_key.c \
					$(PATH_SRC)/panels/game/player/map_zoom.c \
					$(PATH_SRC)/panels/game/player/player_collides.c \
					$(PATH_SRC)/panels/game/player/player_food.c \
					$(PATH_SRC)/panels/game/player/player_footsteps.c \
					$(PATH_SRC)/panels/game/player/player_forcemovement.c \
					$(PATH_SRC)/panels/game/player/player_movement.c \
					$(PATH_SRC)/panels/game/player/player_movement_effect.c \
					$(PATH_SRC)/panels/game/player/player_teleport.c \
					$(PATH_SRC)/panels/game/player/register_player.c \
					\
					$(PATH_SRC)/panels/game/playergui/init_player_gui.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_ach.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_bg.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_btns.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_char.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_health.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_hunger.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_igtime.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_level.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_name.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_quest.c \
					$(PATH_SRC)/panels/game/playergui/init_playergui_xp.c \
					$(PATH_SRC)/panels/game/playergui/playergui_events.c \
					\
					$(PATH_SRC)/panels/game/game_end.c \
					$(PATH_SRC)/panels/game/init_panel_game.c \
					$(PATH_SRC)/panels/game/load_first_game.c \
					$(PATH_SRC)/panels/game/load_game_map.c \
					$(PATH_SRC)/panels/game/onload_game.c \
					\
					$(PATH_SRC)/panels/game/events/game_event_pause.c \
					$(PATH_SRC)/panels/game/events/game_events.c \
					\
					$(PATH_SRC)/panels/game/fight/end_fight.c \
					$(PATH_SRC)/panels/game/fight/fight_attack_entity.c \
					$(PATH_SRC)/panels/game/fight/fight_attack_player.c \
					$(PATH_SRC)/panels/game/fight/fight_btn_escape.c \
					$(PATH_SRC)/panels/game/fight/fight_btn_heal.c \
					$(PATH_SRC)/panels/game/fight/fight_txt_attacks.c \
					$(PATH_SRC)/panels/game/fight/fight_txt_status.c \
					$(PATH_SRC)/panels/game/fight/get_attack_by_id.c \
					$(PATH_SRC)/panels/game/fight/init_fight_bgobj.c \
					$(PATH_SRC)/panels/game/fight/init_fight_enemyobj.c \
					$(PATH_SRC)/panels/game/fight/init_fight_hpentity.c \
					$(PATH_SRC)/panels/game/fight/init_fight_hpplayer.c \
					$(PATH_SRC)/panels/game/fight/init_fight_playerobj.c \
					$(PATH_SRC)/panels/game/fight/init_panel_fight.c \
					$(PATH_SRC)/panels/game/fight/on_attack_select.c \
					$(PATH_SRC)/panels/game/fight/render_fight_panel.c \
					$(PATH_SRC)/panels/game/fight/start_display_fight.c \
					$(PATH_SRC)/panels/game/fight/start_fight_panel.c \
					$(PATH_SRC)/panels/game/fight/update_fight_stext.c \
					\
					$(PATH_SRC)/panels/game/quests/create_quest_card.c \
					$(PATH_SRC)/panels/game/quests/init_panel_quests.c \
					$(PATH_SRC)/panels/game/quests/panel_quests_events.c \
					\
					$(PATH_SRC)/panels/hud/init_panel_hud.c \
					\
					$(PATH_SRC)/panels/hwp/init_buttons_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_ach_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_down_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_interact_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_inv_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_left_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_player_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_quests_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_right_hwp.c \
					$(PATH_SRC)/panels/hwp/init_key_up_hwp.c \
					$(PATH_SRC)/panels/hwp/init_panel_hwp.c \
					$(PATH_SRC)/panels/hwp/init_texts_hwp.c \
					\
					$(PATH_SRC)/panels/saves/create/init_panel_savecreate.c \
					$(PATH_SRC)/panels/saves/create/save_exists.c \
					$(PATH_SRC)/panels/saves/create/init_panel_savecelem.c \
					$(PATH_SRC)/panels/saves/create/update_save_arrow.c \
					$(PATH_SRC)/panels/saves/create/update_save_name.c \
					\
					$(PATH_SRC)/panels/saves/list/handle_savelist_events.c \
					$(PATH_SRC)/panels/saves/list/handle_savelist_render.c \
					$(PATH_SRC)/panels/saves/list/init_panel_savelist.c \
					\
					$(PATH_SRC)/panels/settings/convert_keys.c \
					$(PATH_SRC)/panels/settings/create_key_text.c \
					$(PATH_SRC)/panels/settings/handle_key_change.c \
					$(PATH_SRC)/panels/settings/get_assigned_key.c \
					$(PATH_SRC)/panels/settings/handle_fps_change.c \
					$(PATH_SRC)/panels/settings/handle_volume_change.c \
					$(PATH_SRC)/panels/settings/init_panel_buttons.c \
					$(PATH_SRC)/panels/settings/init_panel_settings.c \
					$(PATH_SRC)/panels/settings/is_key_already_set.c \
					$(PATH_SRC)/panels/settings/on_settings_render.c \
					$(PATH_SRC)/panels/settings/set_button_key.c \
					\
					$(PATH_SRC)/skill/give_player_skills.c \
					$(PATH_SRC)/skill/read_skills.c \
					\
					$(PATH_SRC)/panels/start/handle_buttons_credits.c \
					$(PATH_SRC)/panels/start/handle_buttons_start.c \
					$(PATH_SRC)/panels/start/init_buttons_start.c \
					$(PATH_SRC)/panels/start/init_panel_start.c \
					$(PATH_SRC)/panels/start/init_start_texts.c \
					\
					$(PATH_SRC)/player/add_player_food.c \
					$(PATH_SRC)/player/add_player_health.c \
					$(PATH_SRC)/player/add_player_xp.c \
					\
					$(PATH_SRC)/register/register_tileset.c \
					\
					$(PATH_SRC)/saves/init_default_save.c \
					$(PATH_SRC)/saves/load_saves.c \
					$(PATH_SRC)/saves/clear_save_name.c \
					$(PATH_SRC)/saves/read_inventory.c \
					$(PATH_SRC)/saves/read_pickitems.c \
					$(PATH_SRC)/saves/read_save.c \
					$(PATH_SRC)/saves/save_attributes.c \
					$(PATH_SRC)/saves/save_inventory.c \
					$(PATH_SRC)/saves/save_pickitem.c \
					$(PATH_SRC)/saves/save_player.c \
					$(PATH_SRC)/saves/save_position.c \
					$(PATH_SRC)/saves/save_save.c \
					$(PATH_SRC)/saves/save_skills.c \
					\
					$(PATH_SRC)/screenshot/get_screenshot_name.c \
					$(PATH_SRC)/screenshot/take_screenshot.c \
					\
					$(PATH_SRC)/settings/game_settings.c \
					$(PATH_SRC)/settings/parse_settings_attributes.c \
					$(PATH_SRC)/settings/parse_settings_keys.c \
					$(PATH_SRC)/settings/read_settings.c \
					$(PATH_SRC)/settings/save_settings.c \
					$(PATH_SRC)/settings/update_fps.c \
					$(PATH_SRC)/settings/update_playerid.c \
					$(PATH_SRC)/settings/update_volume.c \
					\
					$(PATH_SRC)/stage/stage_free.c \
					$(PATH_SRC)/stage/stage_init.c \
					\
					$(PATH_SRC)/game_exit.c \
					$(PATH_SRC)/game_init.c \
					$(PATH_SRC)/game_start.c \
					$(PATH_SRC)/game_static.c \
					$(PATH_SRC)/utils/int_to_str.c \
					$(PATH_SRC)/utils/append_str.c \
					$(PATH_SRC)/utils/check_assets.c \
					$(PATH_SRC)/utils/replace_char.c \
					$(PATH_SRC)/utils/str_endswith.c \
					$(PATH_SRC)/utils/my_arrcount.c \
					$(PATH_SRC)/utils/my_strtok.c \
					$(PATH_SRC)/utils/time_utils.c \
					$(PATH_SRC)/main.c

OBJ				= $(patsubst %.c,$(PATH_BUILD)/%.o,$(SRC))

SRC_COUNT		:= $(words $(SRC))
SRC_ID			= 0
PROGRESS		= python3 ./build/_make_progress.py

DEBUG_FLAGS		= -g
INCLUDE_FLAGS	= -I include
INCLUDE_FLAGS   += -I $(PATH_LIBS)/files/include
INCLUDE_FLAGS	+= -I $(PATH_LIBS)/neptunia-lib/include
INCLUDE_FLAGS   += -I $(PATH_LIBS)/tiled/include
INCLUDE_FLAGS   += -I $(PATH_LIBS)/csfml/include

LIB_FLAGS		= -L lib/files -lfiles
LIB_FLAGS		+= -L lib/neptunia-lib -lnep
LIB_FLAGS		+= -L lib/tiled -ltiled
LIB_FLAGS       += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

C_WARNING_FLAGS = -Wextra -Wall -Wno-unused-command-line-argument -Wno-deprecated-declarations -g

C_FLAGS 		= $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

NAME			= my_rpg

$(PATH_BUILD)/%.o: %.c
	@$(eval SRC_ID=$(shell echo $$(($(SRC_ID)+1))))
	@$(PROGRESS) --stepno=$(SRC_ID) --nsteps=$(SRC_COUNT) [$(NAME)] Compiling $<; true
	@mkdir -p $(patsubst %/,%,$(dir $@))
	@gcc -c $< -o $@ $(C_FLAGS) -O

all: build_libs my_rpg
.PHONY : all

$(NAME): $(OBJ)
	@gcc -o $@ $(OBJ) $(LIB_FLAGS) $(DEBUG_FLAGS)
	@$(PROGRESS) --stepno=$(SRC_ID) --nsteps=$(SRC_COUNT) --end [$(NAME)] Build success; true
.PHONY : my_rpg

build_libs:
	@make -C lib/files
	@make -C lib/neptunia-lib
	@make -C lib/tiled

clean:
	@rm -f $(OBJ)
	@find . -name "*.o" -delete
.PHONY : clean

fclean:	clean
	@rm -f my_rpg
	@find . -name "*.out" -delete
	@find . -name "*.gch" -delete
	@find . -name "*.a" -delete
	@find . -name "*.o" -delete
	@find . -name "*.tmp" -delete
	@find . -name ".DS_Store" -delete # MacOS clean support
	@rm -rf $(BNAME).dSYM/ # MacOS clean support

re:	fclean all