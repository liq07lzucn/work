#!/usr/bin/env bash

rm -f qgsII*
rm -f rValues.txt
rm -f finalMIP.txt
rm -f weightAll.txt
rm -f SSD.root
rm -f VEM.txt
rm -f eValues.txt
rm -f MIP_r_bins.txt
for e in {0..20..1}
do
    
  #  for i in {550..3450..100}
    for (( i=1000; i<=4000; i=i+step ))
    do
	factor=$(bc <<< 1.1 )
	rs21=$(bc <<< "scale=2; $factor*$i")
	rs20=$(bc <<< "scale=2; $i*0.9")
	rs2=$(bc <<< "scale=2; $rs21/0.9")
	step=$(bc -l <<< "scale=2; $rs2-$i")
	step=$(printf "%.0f" $step)
	echo ${rs2}
	
	/remote/tesla/bmanning/work/Modules/CORSIKA_thin/CORSIKA_thin_v2.0-muon/./usereadpart /remote/tesla/bmanning/data/qgsII3/proton/10E19/0deg/DAT200006.part <<EOF
    ${rs20}										 
    ${rs21}
EOF

	wait

	mv *weight.txt weightAll.txt


	/remote/tesla/bmanning/work/Geant4Simulations/SSD-build/./SSDSimulation qgs* <<EOF
${i}
${i}
EOF

	rm -f qgsII*

	/remote/tesla/bmanning/work/Modules/Merge/./merge

    done
mv MIP_r_bins.txt /remote/tesla/bmanning/data/SimulationData/proton/10E19/0deg/Muon${e}MIP.txt

done
#/remote/tesla/bmanning/work/Modules/plot/./plot 

