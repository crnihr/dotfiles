#!/bin/bash

case "$1" in
    --toggle)
        if [ "$(pgrep -x zentile)" ]; then
            xdotool key "Control_L+Shift_L+u"
            sleep 2
            killall -q zentile
        else
            zentile &
            sleep 2
            xdotool key "Control_L+Shift_L+t"
        fi
        ;;
    *)
        if [ "$(pgrep -x zentile)" ]; then
            echo ""
        else
            echo ""
        fi
        ;;
esac


