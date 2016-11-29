#!/usr/bin/env python

import Image
import ImageChops
import ImageFilter
import os
import sys



fileOryg = sys.argv[1]
 
# open image
Im = Image.open(fileOryg)


fileBW = sys.argv[2]
 
# convert to black & white
ImBW = Im.convert('1')
ImBW.save(fileBW,"BMP")

os.system('./RoboCorePrinterImageConverter sample_output.txt')

