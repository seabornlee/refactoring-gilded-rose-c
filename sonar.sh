#!/bin/sh

sed "s/user/$1/g" sonar-project.properties > src/sonar-project.properties