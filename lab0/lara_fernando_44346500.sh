#!/bin/bash
# EJERCICIO 1: Modelo del procesador
grep "model name" /proc/cpuinfo | cut -d ':' -f2-
# EJERCICIO 2: Número de unidades de ejecución (cores)
grep "model name" /proc/cpuinfo | wc -l
# EJERCICIO 3: Lista de nombres de usuarios para red social de superhéroes
curl -s https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv | awk -F ";" '{print $2}' | sed '1d' | tr ' ' '_' | sed '/^$/d' | tr '[:upper:]' '[:lower:]' > superheroes_usuarios.txt  
# EJERCICIO 4A: Día de máxima temperatura en Córdoba
sort -k5,5n datos/weather_cordoba.in | tail -1 | awk '{print $1"-"$2"-"$3}'
# EJERCICIO 4B: Día de mínima temperatura en Córdoba
sort -k6,6n datos/weather_cordoba.in | head -1 | awk '{print $1"-"$2"-"$3}'
# EJERCICIO 5: Ordenar jugadores de tenis por ranking
sort -k3,3n datos/atpplayers.in
# EJERCICIO 6: Ordenar tabla de Superliga por puntos y diferencia de goles
awk '{print $0, $7-$8}' datos/superliga.in | sort -k2,2nr -k9,9nr | awk '{$9=""; print}'
# EJERCICIO 7: MAC address de la placa WiFi del equipo
ip link | grep "link/ether" | grep -o -E '([0-9a-f]{2}:){5}[0-9a-f]{2}' | head -1
# EJERCICIO 8: Renombrar archivos de subtítulos
for f in serie_prueba/*_es.srt; do mv "$f" "${f/_es/}"; done
# EJERCICIO 9A: Recortar video con ffmpeg
ffmpeg -ss 2 -i prueba.mp4 -t $(echo "$(ffprobe -v error -show_entries format=duration -of csv=p=0 prueba.mp4) - 4" | bc) -c copy salida.mp4
# EJERCICIO 9B: Mezclar audio con ffmpeg
ffmpeg -i pista1.m4a -i pista2.m4a -filter_complex "[0:a][1:a]amix=inputs=2:duration=longest" -c:a aac salida.m4a
y 