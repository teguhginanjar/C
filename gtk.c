#include <gtk/gtk.h>

GtkWidget * window = NULL;

GtkWidget * 
create_window (void)
{
	GtkWidget * w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (w), 400, 200);
	
	
	GtkWidget * mbar = gtk_menu_bar_new ();
	GtkWidget * file, * preferences, * help; 
	file = gtk_menu_item_new_with_mnemonic ("_File");
	preferences = gtk_menu_item_new_with_mnemonic ("_Preferences");
	help = gtk_menu_item_new_with_mnemonic ("_Help");
	
	gtk_menu_shell_append (GTK_MENU_SHELL (mbar), file);
	gtk_menu_shell_append (GTK_MENU_SHELL (mbar), preferences);
	gtk_menu_shell_append (GTK_MENU_SHELL (mbar), help);
	
	
	GtkWidget * subfile, 
			  * subpreferences, 
			  * subhelp;
	
	subfile = gtk_menu_new ();
	subpreferences = gtk_menu_new ();
	subhelp  = gtk_menu_new ();
	
	GtkWidget * itemopen, 
			  * itemedit, 
			  * itemsave, 
			 
			  * itemquit, 
					  
			  * itemabout;
			  
			  
	itemopen = gtk_menu_item_new_with_label ("Open");
	itemsave = gtk_menu_item_new_with_label ("Save");
	itemquit = gtk_menu_item_new_with_label ("Quit");
	
	itemabout = gtk_menu_item_new_with_label ("About");
	itemedit = gtk_menu_item_new_with_label ("Help");
	
	
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (file), subfile);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (preferences), subpreferences);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (help), subhelp);


	gtk_menu_shell_append (GTK_MENU_SHELL (subfile), itemopen);
	gtk_menu_shell_append (GTK_MENU_SHELL (subfile), itemsave);
	gtk_menu_shell_append (GTK_MENU_SHELL (subfile), itemquit);
	
	
	gtk_menu_shell_append (GTK_MENU_SHELL (subpreferences), itemedit);
	gtk_menu_shell_append (GTK_MENU_SHELL (subhelp), itemabout);
	
	
	g_signal_connect (itemquit, "button-press-event", G_CALLBACK (gtk_main_quit), NULL);
	
	//gtk_container_add (GTK_CONTAINER (w), mbar);

	GtkWidget * mbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget * menubarbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget * contenbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	
	gtk_container_add (GTK_CONTAINER (w), mbox);
	gtk_box_pack_start (GTK_BOX (mbox), menubarbox, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (mbox), contenbox, FALSE, TRUE, 0);
	//gtk_container_add (GTK_CONTAINER (menubarbox), mbar);
	gtk_box_pack_start (GTK_BOX (menubarbox), mbar, FALSE, TRUE, 0);
	
		
	gtk_widget_show_all (mbar);
	
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
