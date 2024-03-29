[Variables]
Volume_X =1640

[Metadata]
Name=Pratous\\Volume
Author=reddit.com/u/khanhas
Description=Display volume, increase and decrease volume by mouse scroll, click at speaker icon to mute. Click at volume number to activate volume slider and audio device changer.

[VolumeLevel]
Measure=Plugin
Plugin=Win7AudioPlugin
Group = Volume

[VolumeLevelCalc]
Measure=Calc
Formula=VolumeLevel <= 0 ? 0 : VolumeLevel
IfCondition=VolumeLevelCalc = 0
IfTrueAction=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
IfCondition2=(VolumeLevelCalc <= 50) && (VolumeLevelCalc > 0)
IfTrueAction2=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
IfCondition3=VolumeLevelCalc > 50 
IfTrueAction3=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
Group = Volume

[VolumeIcon]
Meter=String
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor1#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Volume_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!CommandMeasure VolumeLevel "ToggleMute"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
Group=Volume
DynamicVariables=1

[Volume]
Meter=String
MeasureName=VolumeLevelCalc
Postfix=%
FontFace=#Font_Face#
FontSize=#Font_Size#
FontWeight=#Font_Weight#
FontColor=#TextColor1##Font_Opacity#
AntiAlias=1
StringAlign=LeftCenter
X=8R
Y=r
MouseScrollDownAction=[!CommandMeasure VolumeLevel "ChangeVolume -5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
MouseScrollUpAction  =[!CommandMeasure VolumeLevel "ChangeVolume +5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
LeftMouseUpAction =[!WriteKeyValue Variables Curr_X ([VolumeIcon:X]+([VolumeIcon:W]+[Volume:W])/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Scripts\VolumeControl.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Scripts\VolumeControl.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Scripts\VolumeControl.ini"][!ToggleConfig "#ROOTCONFIG#\Scripts" "VolumeControl.ini"]
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
DynamicVariables=1
SolidColor=0,0,0,1
Group=Volume
RightMouseUpAction=["sndvol.exe"]
