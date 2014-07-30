#include <gtk/gtk.h>

GtkWidget * window = NULL;


static void 
show_dialog_msg ()
{
	const char * authors [] = { "Teguh Ginanjar", "Pahrudin", "Lemmy Kilmister", "oppo", NULL };
	GtkWidget * dialog = gtk_about_dialog_new ();
	//GdkPixbuf * logo = gdk_pixbuf_new_from_file ("./images/pic.png", NULL);
	gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog), "(C) Delameta Bilano, 2013");
	//gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG (dialog), logo);
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog), "0.1");
	gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG (dialog), authors);
	gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog), "tghgnjr@gmail.com");
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}


GtkWidget * 
create_window (void)
{
	GtkWidget * w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (w), -1, -1);
	
	
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
	itemedit = gtk_menu_item_new_with_label ("Edit");
	
	
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (file), subfile);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (preferences), subpreferences);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (help), subhelp);


	gtk_menu_shell_append (GTK_MENU_SHELL (subfile), itemopen);
	gtk_menu_shell_append (GTK_MENU_SHELL (subfile), itemsave);
	gtk_menu_shell_append (GTK_MENU_SHELL (subfile), itemquit);
	
	
	gtk_menu_shell_append (GTK_MENU_SHELL (subpreferences), itemedit);
	gtk_menu_shell_append (GTK_MENU_SHELL (subhelp), itemabout);
	
	
	g_signal_connect (itemquit, "button-press-event", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect (itemabout, "button-press-event", G_CALLBACK (show_dialog_msg), NULL);
	
	//gtk_container_add (GTK_CONTAINER (w), mbar);

	GtkWidget * mbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget * menubarbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget * contenbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	
	gtk_container_add (GTK_CONTAINER (w), mbox);
	gtk_box_pack_start (GTK_BOX (mbox), menubarbox, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (mbox), contenbox, FALSE, TRUE, 0);


	gtk_box_pack_start (GTK_BOX (menubarbox), mbar, FALSE, TRUE, 0);
	GtkWidget * sep = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_box_pack_start (GTK_BOX (contenbox), sep, FALSE, TRUE, 0);
			
	gtk_window_set_position (GTK_WINDOW (w), GTK_WIN_POS_CENTER);
	gtk_widget_show_all (mbar);
	
	g_signal_connect (w, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	
	

	GtkWidget * boxh = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);

	gtk_box_pack_start (GTK_BOX (contenbox), boxh, FALSE, TRUE, 5);
	
	GtkWidget * combo1 = gtk_combo_box_text_new ();
	GtkWidget * combo2 = gtk_combo_box_text_new ();
	GtkWidget * combo3 = gtk_combo_box_text_new ();
	
	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo1), "ch combo1");
	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo2), "ch combo2");
	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo3), "ch combo3");
	
	
	
	
	gtk_combo_box_set_active (GTK_COMBO_BOX (combo1), 0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (combo2), 0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (combo3), 0);
	
	
	
	gtk_box_pack_start (GTK_BOX (boxh), combo1, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (boxh), combo2, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (boxh), combo3, TRUE, TRUE, 0);


	GtkWidget * g = gtk_grid_new ();
	

	GtkWidget * btn[6] ;
	
	int i = 0;
	const char * btnstr [] = {"cut paper", "print text",  "print image", "ch font size", "clear", "feed", NULL};
	
	for (i=0; i<6; i++) {
		
		btn[i] = gtk_button_new_with_label (btnstr[i]); 
		
	}
	
	gtk_grid_attach (GTK_GRID (g), btn[0], 0, 0, 1, 1);
	gtk_grid_attach (GTK_GRID (g), btn[1], 1, 0, 1, 1);
	gtk_grid_attach (GTK_GRID (g), btn[2], 2, 0, 1, 1);
	
	
	gtk_grid_attach (GTK_GRID (g), btn[3], 0, 1, 1, 1);
	gtk_grid_attach (GTK_GRID (g), btn[4], 1, 1, 1, 1);
	gtk_grid_attach (GTK_GRID (g), btn[5], 2, 1, 1, 1);
	
	
	gtk_grid_set_row_spacing (GTK_GRID (g), 5);
	gtk_grid_set_column_spacing (GTK_GRID (g), 5);
	
	
	
	gtk_box_pack_start (GTK_BOX (contenbox), g, TRUE,  TRUE, 0);
	
	gtk_widget_show_all (contenbox);

	gtk_container_set_border_width (GTK_CONTAINER (w), 5);

	

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
