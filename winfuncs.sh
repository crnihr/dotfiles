#!/bin/bash

#todo:
# cancel for tile function
# determine what windows are maximized and re-max after the "window select" function
# determine what windows are non-resizable by the user so that the script doesn't resize them
# cascade also shaded windows

# winfuncs.sh select
# winfuncs.sh tile
# winfuncs.sh tiletwo
# winfuncs.sh tiletwol
# winfuncs.sh tiletwor
# winfuncs.sh tilethree
# winfuncs.sh tilethreev
# winfuncs.sh stacktwo
# winfuncs.sh cascade
# winfuncs.sh showdesktop

# set gaps (0 removes gaps)
outer_gaps=0
inner_gaps=0

# set gaps for 'select' mode
expose_gaps=20

# set desktop dimensions
display_width=$(xdotool getdisplaygeometry | cut -d" " -f1)
display_height=$(xdotool getdisplaygeometry | cut -d" " -f2)

# desktop height without panel(s)
desktop_height=$(xprop -root _NET_WORKAREA | awk '{ print $6 }' | cut -d"," -f1)

# window decorations
window_id=$(xdotool getactivewindow)
titlebar_offset=$(xwininfo -id "$window_id" | awk '/Relative upper-left Y:/ { print $4 }')

# top panel
top_bar=$(xprop -root _NET_WORKAREA | awk '{ print $4 }' | cut -d"," -f1)

# bottom panel (not needed)
bottom_bar=`expr $display_height - $desktop_height - $top_bar`

function get_desktop_dim {	
	if (( ${#DIM[@]} == 0 )) ; then	       
		DIM=(`expr $display_width - $outer_gaps \* 2` `expr $desktop_height - $outer_gaps \* 2`)
	fi
}

# which workspace we're on
function get_workspace {
	if [[ "$DTOP" == "" ]] ; then
		DTOP=`xdotool get_desktop`
	fi
}

function is_desktop {
	xwininfo -id "$*" | grep '"Desktop"'
	return "$?"
}

function get_visible_window_ids {
	if (( ${#WDOWS[@]} == 0 )) ; then
		WDOWS=(`xdotool search --desktop $DTOP --onlyvisible "" 2>/dev/null`)
	fi
}

function win_showdesktop {
	get_workspace
	get_visible_window_ids

	command="search --desktop $DTOP \"\""

	if (( ${#WDOWS[@]} > 0 )) ; then
		command="$command windowminimize %@"
	else
		command="$command windowraise %@"
	fi

	echo "$command" | xdotool -
}

function win_tile_two {
	get_desktop_dim

	wid1=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid1" && return

	wid2=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid2" && return

	half_w=`expr ${DIM[0]} / 2`
	win_h=${DIM[1]}

	commands="windowsize $wid1 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowsize $wid2 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowmove $wid1 $outer_gaps `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid2 `expr $half_w + $outer_gaps + $inner_gaps` `expr $top_bar + $outer_gaps`"
	commands="$commands windowraise $wid1"
	commands="$commands windowraise $wid2"

	wmctrl -i -r $wid1 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid2 -b remove,maximized_vert,maximized_horz

	echo "$commands" | xdotool -
}

function win_tile_two_left {
	get_desktop_dim

	wid1=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid1" && return

	wid2=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid2" && return

	half_w=`expr ${DIM[0]} / 3`
	win_h=${DIM[1]}

	commands="windowsize  $wid1 `expr $half_w \* 2 - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowsize $wid2 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowmove $wid1 $outer_gaps `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid2 `expr $half_w \* 2 + $outer_gaps + $inner_gaps` `expr $top_bar + $outer_gaps`"
	commands="$commands windowraise $wid1"
	commands="$commands windowraise $wid2"

	wmctrl -i -r $wid1 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid2 -b remove,maximized_vert,maximized_horz

	echo "$commands" | xdotool -
}

function win_tile_two_right {
	get_desktop_dim

	wid1=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid1" && return

	wid2=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid2" && return

	half_w=`expr ${DIM[0]} / 3`
	win_h=${DIM[1]}

	commands="windowsize  $wid1 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowsize $wid2 `expr $half_w \* 2 - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowmove $wid1 $outer_gaps `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid2 `expr $half_w + $outer_gaps + $inner_gaps` `expr $top_bar + $outer_gaps`"
	commands="$commands windowraise $wid1"
	commands="$commands windowraise $wid2"

	wmctrl -i -r $wid1 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid2 -b remove,maximized_vert,maximized_horz

	echo "$commands" | xdotool -
}

function win_stack_two {
	get_desktop_dim

	wid1=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid1" && return

	wid2=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid2" && return

	win_w=${DIM[0]}
        half_h=`expr ${DIM[1]} / 2`

	commands="windowsize $wid1 `expr $win_w` `expr $half_h - $titlebar_offset - $inner_gaps`"
	commands="$commands windowsize $wid2 `expr $win_w` `expr $half_h - $titlebar_offset - $inner_gaps`"
	commands="$commands windowmove $wid1 $outer_gaps `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid2 $outer_gaps `expr $half_h + $top_bar + $outer_gaps + $inner_gaps`"
	commands="$commands windowraise $wid1"
	commands="$commands windowraise $wid2"

	wmctrl -i -r $wid1 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid2 -b remove,maximized_vert,maximized_horz

	echo "$commands" | xdotool -
}


function win_tile_three {
	get_desktop_dim

	wid1=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid1" && return

	wid2=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid2" && return
	
	wid3=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid3" && return

        win_h=${DIM[1]}
        half_w=`expr ${DIM[0]} / 2`
	half_h=`expr ${win_h} / 2`

	commands="windowsize $wid1 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowsize $wid2 `expr $half_w - $inner_gaps` `expr $half_h - $titlebar_offset - $inner_gaps`"
	commands="$commands windowsize $wid3 `expr $half_w - $inner_gaps` `expr $half_h - $titlebar_offset - $inner_gaps`"
	commands="$commands windowmove $wid1 $outer_gaps `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid2 `expr $half_w + $outer_gaps + $inner_gaps` `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid3 `expr $half_w + $outer_gaps + $inner_gaps` `expr $half_h + $top_bar + $outer_gaps + $inner_gaps`"
	commands="$commands windowraise $wid1"
	commands="$commands windowraise $wid2"
	commands="$commands windowraise $wid3"

	wmctrl -i -r $wid1 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid2 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid3 -b remove,maximized_vert,maximized_horz

	echo "$commands" | xdotool -
}

function win_tile_three_v {
	get_desktop_dim

	wid1=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid1" && return

	wid2=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid2" && return
	
	wid3=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid3" && return

        win_h=${DIM[1]}
        half_w=`expr ${DIM[0]} / 3`

	commands="windowsize $wid1 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowsize $wid2 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowsize $wid3 `expr $half_w - $inner_gaps` `expr $win_h - $titlebar_offset`"
	commands="$commands windowmove $wid1 $outer_gaps `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid2 `expr $half_w + $outer_gaps + $inner_gaps / 2` `expr $top_bar + $outer_gaps`"
	commands="$commands windowmove $wid3 `expr $half_w \* 2 + $outer_gaps + $inner_gaps` `expr $top_bar + $outer_gaps`"
	commands="$commands windowraise $wid1"
	commands="$commands windowraise $wid2"
	commands="$commands windowraise $wid3"

	wmctrl -i -r $wid1 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid2 -b remove,maximized_vert,maximized_horz
	wmctrl -i -r $wid3 -b remove,maximized_vert,maximized_horz

	echo "$commands" | xdotool -
}

function win_tile {
	get_workspace
	get_visible_window_ids

	(( ${#WDOWS[@]} < 1 )) && return;

	get_desktop_dim

	# determine how many rows and columns we need
	cols=`echo "sqrt(${#WDOWS[@]})" | bc`
	rows=$cols
	wins=`expr $rows \* $cols`

	if (( "$wins" < "${#WDOWS[@]}" )) ; then
		cols=`expr $cols + 1`
		wins=`expr $rows \* $cols`
		if (( "$wins" < "${#WDOWS[@]}" )) ; then
	    rows=`expr $rows + 1`
	    wins=`expr $rows \* $cols`
		fi
	fi

	(( $cols < 1 )) && cols=1;
	(( $rows < 1 )) && rows=1;

	win_w=`expr ${DIM[0]} / $cols`
	win_h=`expr ${DIM[1]} / $rows`

	# do tiling 
	x=0; y=0; commands=""
	for window in ${WDOWS[@]} ; do
		wmctrl -i -r $window -b remove,maximized_vert,maximized_horz

		commands="$commands windowsize $window `expr $win_w - $inner_gaps \* 2` `expr $win_h - $titlebar_offset - $inner_gaps \* 2`"
		commands="$commands windowmove $window `expr $x \* $win_w + $outer_gaps` `expr $y \* $win_h + $top_bar + $outer_gaps`"

		x=`expr $x + 1`
		if (( $x > `expr $cols - 1` )) ; then
	    	      x=0
	    	      y=`expr $y + 1`
		fi
	done

	echo "$commands" | xdotool -
}

function expose {
	get_workspace
	get_visible_window_ids

	(( ${#WDOWS[@]} < 1 )) && return;

	get_desktop_dim

	# determine how many rows and columns we need
	cols=`echo "sqrt(${#WDOWS[@]})" | bc`
	rows=$cols
	wins=`expr $rows \* $cols`

	if (( "$wins" < "${#WDOWS[@]}" )) ; then
		cols=`expr $cols + 1`
		wins=`expr $rows \* $cols`
		if (( "$wins" < "${#WDOWS[@]}" )) ; then
	    rows=`expr $rows + 1`
	    wins=`expr $rows \* $cols`
		fi
	fi

	(( $cols < 1 )) && cols=1;
	(( $rows < 1 )) && rows=1;

	win_w=`expr ${DIM[0]} / $cols`
	win_h=`expr ${DIM[1]} / $rows`
		
	# do tiling 
	x=0; y=0; commands=""
	for window in ${WDOWS[@]} ; do
		wmctrl -i -r $window -b remove,maximized_vert,maximized_horz

		commands="$commands windowsize $window `expr $win_w - $expose_gaps \* 2` `expr $win_h - $titlebar_offset - $expose_gaps \* 2`"
		commands="$commands windowmove $window `expr $x \* $win_w + $expose_gaps` `expr $y \* $win_h + $top_bar + $expose_gaps`"

		x=`expr $x + 1`
		if (( $x > `expr $cols - 1` )) ; then
	    	      x=0
	    	      y=`expr $y + 1`
		fi
	done

	echo "$commands" | xdotool -
}

function win_cascade {
	get_workspace
	get_visible_window_ids

	(( ${#WDOWS[@]} < 1 )) && return;

	x=0; y=0; commands=""
	for window in ${WDOWS[@]} ; do
		wmctrl -i -r $window -b remove,maximized_vert,maximized_horz

		commands="$commands windowsize $window 1024 640"
		commands="$commands windowmove $window `expr $x + $outer_gaps` `expr $y + $top_bar + $outer_gaps`"

		x=`expr $x + 100`
	  y=`expr $y + 80`
	done

	echo "$commands" | xdotool -
}

function win_select {
	get_workspace
	get_visible_window_ids

	(( ${#WDOWS[@]} < 1 )) && return;

	# store window positions and widths
	i=0
	for window in ${WDOWS[@]} ; do
		GEO=`xdotool getwindowgeometry $window | grep Geometry | sed 's/.* \([0-9].*\)/\1/g'`;
		height[$i]=`echo $GEO | sed 's/\(.*\)x.*/\1/g'`
		width[$i]=`echo $GEO | sed 's/.*x\(.*\)/\1/g'`

		# ( xwininfo gives position not ignoring titlebars and borders, unlike xdotool )
		POS=(`xwininfo -stats -id $window | grep 'geometry ' | sed 's/.*[-+]\([0-9]*[-+][0-9*]\)/\1/g' | sed 's/[+-]/ /g'`)
		posx[$i]=${POS[0]}
		posy[$i]=${POS[1]}

		i=`expr $i + 1`
	done

	# tile windows
	expose

	# select a window
	wid=`xdotool selectwindow 2>/dev/null`

	is_desktop "$wid" && return

	# restore window positions and widths
	i=0; commands=""
	for (( i=0; $i<${#WDOWS[@]}; i++ )) ; do
		commands="$commands windowsize ${WDOWS[i]} ${height[$i]} ${width[$i]}"
		commands="$commands windowmove ${WDOWS[i]} ${posx[$i]} ${posy[$i]}"
	done

	commands="$commands windowraise $wid"

	echo "$commands" | xdotool -
}

for command in ${@} ; do
	if [[ "$command" == "tile" ]] ; then
		win_tile
	elif [[ "$command" == "select" ]] ; then
		win_select
	elif [[ "$command" == "tiletwo" ]] ; then
		win_tile_two
	elif [[ "$command" == "tiletwol" ]] ; then
		win_tile_two_left
	elif [[ "$command" == "tiletwor" ]] ; then
		win_tile_two_right
	elif [[ "$command" == "stacktwo" ]] ; then
		win_stack_two
	elif [[ "$command" == "tilethree" ]] ; then
		win_tile_three
	elif [[ "$command" == "tilethreev" ]] ; then
		win_tile_three_v
        elif [[ "$command" == "cascade" ]] ; then
		win_cascade
	elif [[ "$command" == "showdesktop" ]] ; then
		win_showdesktop
	fi
done
