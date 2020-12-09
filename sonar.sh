#!/bin/sh

sed "s/user/$1/g" sonar-project.properties > src/sonar-project.properties

docker run \
    --rm \
    -e SONAR_HOST_URL="$2" \
    -v "${PWD}/src/:/usr/src" \
    sonarsource/sonar-scanner-cli