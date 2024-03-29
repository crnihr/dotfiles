[Variables]
Workspacemanager_x=0
Maximum_Workspace = 5
Workspace_Number_Gap = 15

[Metadata]
Name=Papirus\\Workspace Manager
Author=reddit.com/u/khanhas
Description=Click at number to change to desired workspace. Middle click to create new workspace. Choose a windows then hold Shift + click at number to move that window to desired workspace.

[GetWorkspaceVariable]
Measure=PLugin
Plugin=RunCommand
Program=""#@#WorkspaceManager.exe" "#PROGRAMPATH#Rainmeter.exe" "Workspace_Total" "Workspace_Current" "#RootConfig#""

[WorkspaceWindowSendMessage]
Measure=Plugin
Plugin=WindowMessagePlugin
WindowName=#@#WorkspaceManager.exe

[WorkspaceScript]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Scripts\script_Workspace.lua

[WorkspaceActionTimer]
Measure=Plugin
Plugin=Actiontimer
ActionList1=Repeat ScriptAnimation,16,1000
ScriptAnimation=!CommandMeasure WorkspaceScript "ChangeWorkspaceAnimation()"

[WorkspaceCurrent]
Meter=Shape
X=(#Bar_OffsetX#+#workspacemanager_x#)
Y=(#Bar_OffsetY#)
W=10
IndicatorTrait = StrokeWidth 0 | Fill Color #TextColor1##Indicator_Opacity#
DynamicVariables=1

[StyleWSNumber]
X=R
Y=(#Bar_OffsetY#+#Bar_Height#/2)
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontColor=#TextColor1#
FontSize=#Font_Size#
AntiAlias=1
SolidColor=0,0,0,1
H=28
W=(#Workspace_Number_Gap#*2)
StringAlign=CenterCenter
Hidden=1

[Workspace1]
Meter=String
Text=1
X=(#Bar_OffsetX#+#workspacemanager_x#+#Workspace_Number_Gap#)
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 1"]
RightMouseUpAction=["#@#nircmd.exe" sendkeypress lwin+tab]
DynamicVariables=1 

[Workspace2]
Meter=String
Text=2
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 2"]
RightMouseUpAction=["#@#nircmd.exe" sendkeypress lwin+tab]

[Workspace3]
Meter=String
Text=3
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 3"]
RightMouseUpAction=["#@#nircmd.exe" sendkeypress lwin+tab]

[Workspace4]
Meter=String
Text=4
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 4"]
RightMouseUpAction=["#@#nircmd.exe" sendkeypress lwin+tab]

[Workspace5]
Meter=String
Text=5
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 5"]
RightMouseUpAction=["#@#nircmd.exe" sendkeypress lwin+tab]

[Workspace6]
Meter=String
Text=6
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 6"]
[Workspace7]
Meter=String
Text=7
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 7"]
[Workspace8]
Meter=String
Text=8
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 8"]
[Workspace9]
Meter=String
Text=9
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 9"]
[Workspace10]
Meter=String
Text=10
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 10"]
