#!/bin/bash

sudo su postgres -c '
psql -U postgres -c "create database netb_roulette"
for f in *.sql
do
	psql -U postgres -d "netb_roulette" -f "$f"
done
psql -U postgres -c "create role roulette_admin"
'
