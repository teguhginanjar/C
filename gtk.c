#include <gtk/gtk.h>



GtkWidget * window;




GtkWidget * 
create_window (void)
{
	GtkWidget * w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (w), 400, 400);
	
	
	g_signal_connect (w, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	
	return w;
}



int 
main (int argc, char ** argv)
{
	gtk_init (&argc, &argv);
	
	window  = create_window ();
	
	gtk_widget_show_all (window);
	
	gtk_main ();
	return 0;
}
