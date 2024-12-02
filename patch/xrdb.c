void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			/*if (xrdb != NULL) {
				XRDB_LOAD_COLOR("dwm.normfgcolor", normfgcolor);
				XRDB_LOAD_COLOR("dwm.normbgcolor", normbgcolor);
				XRDB_LOAD_COLOR("dwm.normbordercolor", normbordercolor);
				XRDB_LOAD_COLOR("dwm.normfloatcolor", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.selfgcolor", selfgcolor);
				XRDB_LOAD_COLOR("dwm.selbgcolor", selbgcolor);
				XRDB_LOAD_COLOR("dwm.selbordercolor", selbordercolor);
				XRDB_LOAD_COLOR("dwm.selfloatcolor", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.titlenormfgcolor", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.titlenormbgcolor", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.titlenormbordercolor", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.titlenormfloatcolor", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.titleselfgcolor", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.titleselbgcolor", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.titleselbordercolor", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.titleselfloatcolor", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfgcolor", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormbgcolor", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormbordercolor", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfloatcolor", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.tagsselfgcolor", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.tagsselbgcolor", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.tagsselbordercolor", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsselfloatcolor", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.hidnormfgcolor", hidnormfgcolor);
				XRDB_LOAD_COLOR("dwm.hidnormbgcolor", hidnormbgcolor);
				XRDB_LOAD_COLOR("dwm.hidselfgcolor", hidselfgcolor);
				XRDB_LOAD_COLOR("dwm.hidselbgcolor", hidselbgcolor);
				XRDB_LOAD_COLOR("dwm.urgfgcolor", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.urgbgcolor", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.urgbordercolor", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.urgfloatcolor", urgfloatcolor);
			}*/
			if (xrdb != NULL) {
			        XRDB_LOAD_COLOR("dwm.color0", normbordercolor);
			        XRDB_LOAD_COLOR("dwm.color8", selbordercolor);
			        XRDB_LOAD_COLOR("dwm.color1", normbgcolor);
			        XRDB_LOAD_COLOR("dwm.color0", normfgcolor);
			        XRDB_LOAD_COLOR("dwm.color0", selfgcolor);
			        XRDB_LOAD_COLOR("dwm.color14", selbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", hidnormbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", hidnormfgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", hidselfgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", hidselbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", titlenormbordercolor);
                                XRDB_LOAD_COLOR("dwm.color0", titleselbordercolor);
                                XRDB_LOAD_COLOR("dwm.color1", titlenormbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", titlenormfgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", titleselfgcolor);
                                XRDB_LOAD_COLOR("dwm.color4", titleselbgcolor);
                                XRDB_LOAD_COLOR("dwm.color1", tagsnormbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", tagsnormfgcolor);
                                XRDB_LOAD_COLOR("dwm.color2", tagsselfgcolor);
                                XRDB_LOAD_COLOR("dwm.color4", tagsselbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", tagsselbordercolor);
                                XRDB_LOAD_COLOR("dwm.color0", tagsnormbordercolor);
                                XRDB_LOAD_COLOR("dwm.color0", urgfgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", urgbgcolor);
                                XRDB_LOAD_COLOR("dwm.color0", urgbordercolor);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		alphas[i],
		ColCount
		);
	arrange(NULL);
	focus(NULL);
}
