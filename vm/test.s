.name "yolo"
.comment "swag"

		sti r1,%:live,%1
		sti r1,%-45
		ld %0,r16
live:
		live %1
		zjmp %:live
