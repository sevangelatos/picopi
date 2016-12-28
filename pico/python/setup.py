#!/usr/bin/env python
from setuptools import setup, find_packages
import os

from distutils.core import Extension

#/usr/share/pico/lang/
version = '0.10.2'

extLevensthein = Extension('tts',
                           sources = ['ttsmodule.c', '../tts/tts_engine.c'],
                           libraries=['svoxpico'],
                           )

setup(name='python-tts',
      version=version,
      description="Python simple text to speech module.",
      long_description=open("README.rst").read() + "\n" +
                       open(os.path.join("HISTORY.txt")).read(),
      # Get more strings from http://pypi.python.org/pypi?%3Aaction=list_classifiers
      classifiers=[
        "Programming Language :: Python",
        ],
      include_dirs = ['../tts/'],
      keywords='speech text-to-speech svox',
      author='Spiros Evangelatos',
      author_email='sevangelatos@gmail.com',
      url='http://github.com/sevangelatos/TODO',
      license='GPL',
      packages=find_packages(exclude=['ez_setup']),
      namespace_packages=[],
      include_package_data=True,
      zip_safe=False,
      ext_modules = [extLevensthein],
      install_requires=[
          'setuptools',
          # -*- Extra requirements: -*-
      ],
      entry_points="""
      # -*- Entry points: -*-
      """,
      )