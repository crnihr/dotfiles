[Variables]
Bar_Color=141414
Bar_Opacity=b6
;Font_Opacity=b9
Font_Opacity=ff
Indicator_Opacity=64

Bar_Width =1920
Bar_Height =28
Bar_OffsetX =0
Bar_OffsetY =0

Default=C4C4C4
green=89D287
greenNeon=ADC3B6
ghostpink=E34075
purple=B3A7FF
blue=34B5FE
red=F14336
orange=FF7700
gold=FAD4AF
fluent=aaadff
oker=F19155


Font_Face=AvantGarde LT Medium
Font_Size=10
Font_Weight=500

[ChameleonDesktop]
Measure=Plugin
Plugin=Chameleon
Type=Desktop

[CompareStringVar]
DynamicVariables=1
Measure=String
String=[ChameleonDesktop]
IfMatch=F:\\Wallpapers\\System\\desktop1.jpg
IfMatchAction=[!WriteKeyValue "Variables" "TextColor1" "#gold#"][!WriteKeyValue "Variables" "TextColor2" "#ghostpink#"][!WriteKeyValue "Variables" "PowerColor" "#ghostpink#"]
IfMatch2=F:\\Wallpapers\\System\\desktop2.jpg
IfMatchAction2=[!WriteKeyValue "Variables" "TextColor1" "#gold#"][!WriteKeyValue "Variables" "TextColor2" "#gold#"][!WriteKeyValue "Variables" "PowerColor" "#gold#"]
IfMatch3=F:\\Wallpapers\\System\\desktop3.jpg
IfMatchAction3=[!WriteKeyValue "Variables" "TextColor1" "#Default#"][!WriteKeyValue "Variables" "TextColor2" "#Default#"][!WriteKeyValue "Variables" "PowerColor" "#Default#"]
IfMatch4=F:\\Wallpapers\\System\\desktop4.jpg
IfMatchAction4=[!WriteKeyValue "Variables" "TextColor1" "#ghostpink#"][!WriteKeyValue "Variables" "TextColor2" "#greenNeon#"][!WriteKeyValue "Variables" "PowerColor" "#greenNeon#"]
IfMatch5=F:\\Wallpapers\\System\\desktop5.jpg
IfMatchAction5=[!WriteKeyValue "Variables" "TextColor1" "#fluent#"][!WriteKeyValue "Variables" "TextColor2" "#ghostpink#"][!WriteKeyValue "Variables" "PowerColor" "#ghostpink#"]
IfNotMatchAction=[!WriteKeyValue "Variables" "TextColor1" "#Default#"][!WriteKeyValue "Variables" "TextColor2" "#Default#"][!WriteKeyValue "Variables" "PowerColor" "#Default#"]
OnChangeAction=[!CommandMeasure AdditionalSkinActionTimer2 "Execute 1"]
