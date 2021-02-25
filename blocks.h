//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"t", "sensors | awk '/Core 0/ {print $3}' | cut -c2-5", 10, 0},
	{"", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 10, 0},
	{"/", "cat /sys/class/power_supply/BAT1/capacity 2>/dev/null", 30, 0},
	{"v", "awk -F'[][]' '/Left:/ { print $2 }' <(amixer sget Master)", 0, 10},
	{"", "date '+%d.%m %T'", 1,	0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
