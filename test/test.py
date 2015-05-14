#!/usr/bin/python

import xkeyboard

xkb = xkeyboard.XKeyboard()

print(xkb)

print("xkeyboard.groupCount: " + str(xkb.groupCount()))
print("xkeyboard.groupNames: " + str(xkb.groupNames()))
print("xkeyboard.groupSymbols: " + str(xkb.groupSymbols()))
print("xkeyboard.groupVariants: " + str(xkb.groupVariants()))
print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))
print("xkeyboard.currentGroupName: " + str(xkb.currentGroupName()))
print("xkeyboard.currentGroupSymbol: " + str(xkb.currentGroupSymbol()))
print("xkeyboard.currentGroupVariant: " + str(xkb.currentGroupVariant()))

print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))
print("xkeyboard.setGroupByNum(1)")
xkb.setGroupByNum(1)
print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))
print("xkeyboard.setGroupByNum(0)")
xkb.setGroupByNum(0)
print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))

print("")

print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))
print("xkeyboard.changeGroup(1)")
xkb.changeGroup(1)
print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))
print("xkeyboard.changeGroup(1)")
xkb.changeGroup(1)
print("xkeyboard.currentGroupNum: " + str(xkb.currentGroupNum()))
