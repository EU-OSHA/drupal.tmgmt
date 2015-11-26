#!/usr/bin/env bash

TARGET="EU-OSHA"
if [ $1 ]; then
  TARGET="$@"
fi

php docroot/scripts/run-tests.sh --color --verbose --url http://drupal-tmgmt.local/ $TARGET