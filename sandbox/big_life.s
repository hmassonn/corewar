.name "big life"
.comment "why live once when we can live 21 times"

		st r1,r2
		ld %0,r1
		st r2,106	# writting the programm id at PC + r2
		st r2,106	# ...
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106	# ...
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106
		st r2,106	# ...

live:				# live label
		live %1		# live
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1		# ...
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1		# ...
		zjmp %:live	# jump to live label
