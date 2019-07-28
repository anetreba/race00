void mx_printchar(char c);
void mx_printstr(const char *s);

static void header_lower(int w) {
	if (w == 1)
		mx_printstr("<=>");
	if (w > 1) {
		mx_printstr("<=");
		for(int i = 0; i < w - 2; i++)
			mx_printchar('-');
		mx_printstr("=>");
	}
	mx_printchar('\n');
}

static void stars(int l) {
	if (l % 2 == 0)
		mx_printchar('+');
	else
		mx_printchar('*');
}

static void Neo(int l, int w, int y, int x) {
	for (int i = 0; i < l; i++) {
		stars(i);
		for (int j = 0; j < w; j++) {
			if (i == y && j == x)
				mx_printchar('1');
			else
				mx_printchar('0');
		}
		stars(i);
		mx_printchar('\n');
	}
}

void race00(int map_length, int map_width, int one_y, int one_x) {
	if (one_y > map_length || one_x > map_width)
	 	mx_printchar('\n');
	else if (map_length == 1 && map_width == 1)
	 	mx_printchar('\n');
	else if (map_width > 0 && map_length > 0 && one_y >= 0 && one_x >= 0) {
		header_lower(map_width);
		Neo(map_length, map_width, one_y, one_x);
		header_lower(map_width);
	}
	else
		mx_printchar('\n');
}
