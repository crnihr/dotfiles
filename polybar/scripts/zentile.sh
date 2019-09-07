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
            echo "#1"
        else
            echo "#2"
        fi
        ;;
esac
