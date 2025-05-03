#!/bin/bash

sed -i "s/my_cert/$SSL_CERTIFICATE/g" /etc/nginx/sites-available/default
sed -i "s/my_key/$SSL_CERTIFICATE_KEY/g" /etc/nginx/sites-available/default
sed -i "s/DOMAIN_NAME/${DOMAIN_NAME}/g" /etc/nginx/sites-available/default

nginx -g "daemon off;"
