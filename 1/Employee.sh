echo -e "Address Book\n"

echo -e "File name:"
read fname

touch $fname

echo -e "id \t name \t mobile_no \t salary \t location \t" >> $fname

ch=0
while [ $ch -lt 7 ]
do

echo -e "1) Create Address Book\n"
echo -e "2) View Address Book\n"
echo -e "3) Insert a Record\n"
echo -e "4) Delete a Record\n"
echo -e "5) Modify a Record\n"
echo -e "6) Search a Record\n"
echo -e "7) Exit"




echo "Enter Your Choice:"
read ch

case $ch in 

	1)

	echo "Enter number of records:"
	read n
	
		
	for((i=0;i<$n;i++))
	do
	
	echo "Enter id:"
	read id
	
	echo "Enter name:"
	read name
	
	echo "Enter mobile number:"
	read mno

	echo "Enter salary:"
	read sal
	
	echo "Enter location:"
	read loc
	
	echo -e "$id \t $name \t $mno \t $sal \t $loc" >> $fname
	
	done
	
;;

	2)

	cat  $fname
	
;;

	3) 
	
	echo "Enter id:"
	read id
	
	echo "Enter name:"
	read name
	
	echo "Enter mobile number:"
	read mno

	echo "Enter salary:"
	read sal
	
	echo "Enter location:"
	read loc
	
	echo -e "$id \t $name \t $mno \t $sal \t $loc " >> $fname	

;;
	4)
	
	echo "Enter Employee ID to delete:"
	read id

	if grep -w $id $fname
	then
		grep -wv $id $fname >>temp
		rm $fname
		mv temp $fname	
	else
		echo "record not found"
	fi
		
	
;;
	5)
	echo "Enter Employee ID to modify:"
	read id

	if grep -w $id $fname
	then
		grep -wv $id $fname >>temp
		rm $fname
		mv temp $fname	

		echo "Enter e_id:"
		read id
	
		echo "Enter name:"
		read name
	
		echo "Enter mobile number:"
		read mno

		echo "Enter salary:"
		read sal
	
		echo "Enter location:"
		read loc
	
		echo -e "$id \t $name \t $mno \t $sal \t $loc " >> $fname	
		else
			echo "record not found"
		fi
;;
	
	6)
		echo "Enter Employee id to search:"
		read id
		if grep -w $id $fname
		then
			echo "Record found"
		else
			echo "record not found"
		fi
;;

	*)
		

esac

done















