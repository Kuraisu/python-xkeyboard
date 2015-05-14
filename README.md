# python-xkeyboard
XKeyboard module provides easy access to X11 XKB extension.

Based and extended upon XKeyboard class by https://github.com/jbromley

Usage:
```python
import xkeyboard

xkb = xkeyboard.XKeyboard()

xkb.groupCount()          # Number of available groups
xkb.groupNames()          # Tuple with group names
xkb.groupSymbols()        # Tuple with group symbols
xkb.groupVariants()       # Tuple with group variants
xkb.currentGroupNum()     # Index of active group
xkb.currentGroupName()    # Name of active group
(xkb.currentGroupSymbol() # Symbol of active group
xkb.currentGroupVariant() # Variant of active group

xkb.setGroupByNum(0)      # Set group by index

xkb.changeGroup(1)        # Select next group
xkb.changeGroup(-1)       # Select previous group
```

