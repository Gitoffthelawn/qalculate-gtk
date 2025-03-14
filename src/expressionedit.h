/*
    Qalculate (GTK UI)

    Copyright (C) 2024  Hanna Knutsson (hanna.knutsson@protonmail.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/

#ifndef EXPRESSION_EDIT_H
#define EXPRESSION_EDIT_H

#include <gtk/gtk.h>
#include <stdio.h>

void create_expression_edit();
void update_expression_colors(bool initial, bool text_color_set);
void update_expression_font(bool initial = false);
void set_expression_font(const char *str);
const char *expression_font(bool return_default = false);
void expression_font_modified();
void set_expression_size_request();

GtkWidget *expression_edit_widget();
GtkTextBuffer *expression_edit_buffer();
GtkMenu *expression_edit_popup_menu();

void block_undo();
void unblock_undo();
bool undo_blocked();
void block_expression_history();
void unblock_expression_history();
bool expression_history_blocked();

#ifdef EVENT_CONTROLLER_TEST
gboolean on_expressiontext_key_press_event(GtkEventControllerKey*, guint keyval, guint, GdkModifierType state, gpointer);
#else
gboolean on_expressiontext_key_press_event(GtkWidget *o, GdkEventKey *event, gpointer);
#endif

const char *expression_add_sign();
const char *expression_sub_sign();
const char *expression_times_sign();
const char *expression_divide_sign();
void set_expression_operator_symbols();

std::string get_expression_text();
std::string get_selected_expression_text(bool return_all_if_no_sel = false);
bool expression_is_empty();
void clear_expression_text();
void set_expression_text(const gchar *text);
void expression_select_all();
void expression_save_selection();
void expression_restore_selection();
bool expression_history_up();
bool expression_history_down();
void add_to_expression_history(std::string str);
bool is_at_beginning_of_expression(bool allow_selection = false);
int wrap_expression_selection(const char *insert_before = NULL, bool return_true_if_whole_selected = false);
void focus_keeping_selection();
void focus_expression();
bool expression_modified();
void set_expression_modified(bool b, bool handle, bool autocalc);
void brace_wrap();
void insert_angle_symbol();
void insert_text(const gchar *text);
void expression_insert_date();
void expression_insert_matrix();
void expression_insert_vector();
void overwrite_expression_selection(const gchar *text);
void set_previous_expression(const std::string &str);
const std::string &get_previous_expression();
void restore_previous_expression();
void add_expression_to_undo();
void expression_undo();
void expression_redo();
void clear_expression_history();
void start_expression_spinner();
void stop_expression_spinner();
void store_expression_selection();
void restore_expression_selection();

#define EXPRESSION_STOP 1
#define EXPRESSION_SPINNER 2
#define RESULT_SPINNER 5
#define EXPRESSION_INFO 3
#define EXPRESSION_CLEAR 4
void update_expression_icons(int id = 0);
void showhide_expression_button();
void hide_expression_spinner();
void block_expression_icon_update();
void unblock_expression_icon_update();

bool read_expression_edit_settings_line(std::string &svar, std::string &svalue, int &v);
void write_expression_edit_settings(FILE *file);
bool read_expression_history_line(std::string &svar, std::string &svalue);
void write_expression_history(FILE *file);

#endif /* EXPRESSION_EDIT_H */
