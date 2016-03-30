#!/usr/bin/env python
# encoding: utf-8
"""
build_cmdlinetest_macpro.py

Created by Lucien Schreiber on 2013-05-14.
Copyright (c) 2013 . All rights reserved.
"""

import sys
import os
import build_function
import shutil
import subprocess


def main():
    print (build_function.GetBinaryDirectory())
    print (build_function.GetSourceDirectory())

    # build_function.ClearDirectory()
    # build_function.UpdateMercurial()

    try:
        p = subprocess.Popen("cmake -GXcode " + os.path.join(build_function.GetSourceDirectory(), "app", "cmdlinetest",
                                                             "build") + " -DCMAKE_OSX_ARCHITECTURES:TEXT=x86_64 -DCMAKE_OSX_DEPLOYMENT_TARGET:TEXT=10.7 -DCMAKE_OSX_SYSROOT:PATH=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk -DCMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE:FILE=/Users/lucien/Documents/PROGRAMMATION/64/_LIBWXSVN/bin/wx-config",
                             shell=True, cwd=build_function.GetBinaryDirectory())
        p.wait()
    except:
        print("Error creating makefile")


if __name__ == '__main__':
    main()
