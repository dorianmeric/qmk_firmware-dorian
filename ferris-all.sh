# make ferris/sweep:dorian-callum
# make ferris/sweep:dorian-callum -e CONVERT_TO=promicro_rp2040
clear
make ferris/sweep:dorian-mir -e CONVERT_TO=kb2040
make ferris/sweep:dorian-mir -e CONVERT_TO=promicro_rp2040

# make ferris/sweep:manna-harbour_miryoku -e CONVERT_TO=kb2040
# make ferris/sweep:manna-harbour_miryoku -e CONVERT_TO=promicro_rp2040



 # make json
 # cd users/dorian-mir
 # qmk -v c2json -kb ferris/sweep -km dorian-mir manna-harbour_miryoku.c -o qmkconfig-dorianmir.json
