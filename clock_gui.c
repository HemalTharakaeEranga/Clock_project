#include <stdlib.h>
#include <gtk/gtk.h>
#include <time.h>

static gboolean update_time(gpointer label) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[9]; // HH:MM:SS\0

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format the time string in digital clock format: HH:MM:SS
    sprintf(buffer, "%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    gtk_label_set_text(GTK_LABEL(label), buffer);

    return TRUE; 
}

static void activate(GtkApplication *app) {
    GtkWidget *window;
    GtkWidget *label;
    PangoFontDescription *font_desc;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Digital Clock");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    label = gtk_label_new(NULL);
    GdkRGBA text_color = {0.2, 0.0, 0.4, 1.0}; // Set text color to black
    gtk_widget_override_color(label, GTK_STATE_FLAG_NORMAL, &text_color); // Use GTK_STATE_FLAG_NORMAL instead of GTK_STATE_NORMAL
    GdkRGBA background_color = {1.0, 1.0, 1.0, 1.0}; // Set background color to white
    gtk_widget_override_background_color(label, GTK_STATE_FLAG_NORMAL, &background_color); // Use GTK_STATE_FLAG_NORMAL instead of GTK_STATE_NORMAL

    font_desc = pango_font_description_from_string("Sans Bold 72"); // Set font size to 72
    gtk_widget_override_font(label, font_desc); 
    pango_font_description_free(font_desc);

    gtk_container_add(GTK_CONTAINER(window), label);

    g_timeout_add_seconds(1, update_time, label); 

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.DigitalClock", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}