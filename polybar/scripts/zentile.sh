#!/bin/sh

case "$1" in
    --toggle)
        if [ "$(pgrep -x zentile)" ]; then
            killall -q zentile
        else
            ~/.config/zentile/zentile
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


