from distutils.core import setup, Extension

xkeyboard = Extension('xkeyboard',
		    libraries = ['X11'],
                    sources = [
                	'src/XKeyboard.cpp',
                	'src/xkeyboard-mod.cpp'
            	    ])

setup (name = 'xkeyboard',
       version = '1.1',
       description = 'XKeyboard module provides easy access to X11 XKB extension.',
       license = "GPL2+",
       author = 'Aleksey Yermakov',
       author_email = 'alexey.yermakov@rosalab.ru',
       url = 'http://rosalab.com',
       ext_modules = [xkeyboard])
