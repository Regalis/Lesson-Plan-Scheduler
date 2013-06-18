/* Test code */

#include <iostream>
#include "TimetableGenerator.hpp"

int main() {

	/* Rooms */ // okresla liczbę dostępnych sal oraz ilosc miejsc w salach. W tym przypadku mamy 3 dostępne sale 001, 002, 003 pracownie chemiczna oraz informatyczna
	slimak::TimetableClassroom room001; //numer sali - 001
	room001.id = 1;
	room001.capacity = 30;              //ilosc miejsc w sali 001- 30
	slimak::TimetableClassroom room002;  //numer sali - 002
	room002.id = 2;
	room002.capacity = 30;    //ilosc miejsc w sali 002- 30
        slimak::TimetableClassroom room003;  //numer sali - 003
	room003.id = 3;
	room003.capacity = 30;    //ilosc miejsc w sali 003- 30
        slimak::TimetableClassroom roomchemia;  //pracownie chemiczna
	roomchemia.id = 4;
	roomchemia.capacity = 30;    //ilosc miejsc w sali chemicznej- 30
        slimak::TimetableClassroom roominformatyka;  //pracownie informatyczna
	roominformatyka.id = 5;
	roominformatyka.capacity = 30;    //ilosc miejsc w sali informatycznej- 30
	
	/* Subjects */    // lista przedmiotów
	// polski
	slimak::TimetableSubject polski;  // język polski
	polski.id = 0;
	polski.classrooms.push_back(room001.id);  // moze sie odbywać w salach 001, 002 oraz 003
	polski.classrooms.push_back(room002.id);
        polski.classrooms.push_back(room003.id);
	// matematyka
	slimak::TimetableSubject matematyka;  // matematyka
	matematyka.id = 1;
	matematyka.classrooms.push_back(room001.id); // moze sie odbywać w salach 001, 002 oraz 003
        matematyka.classrooms.push_back(room002.id);
        matematyka.classrooms.push_back(room003.id);
	//fizyka
	slimak::TimetableSubject fizyka;  // fizyka
	fizyka.id = 2;
	fizyka.classrooms.push_back(room001.id); /// moze sie odbywać w salach 001, 002 oraz 003
        fizyka.classrooms.push_back(room002.id);
        fizyka.classrooms.push_back(room003.id);
	// historia
	slimak::TimetableSubject historia;  // historia
	historia.id = 3;
	historia.classrooms.push_back(room001.id); // moze sie odbywać w salach 001, 002 oraz 003
        historia.classrooms.push_back(room002.id);
        historia.classrooms.push_back(room003.id);
	//chemia
	slimak::TimetableSubject chemia;  // chemia
	chemia.id = 4;
	chemia.classrooms.push_back(roomchemia.id); // może sie odbywac tylko w pracowni chemicznej
	//informatyka
	slimak::TimetableSubject informatyka;  // informatyka
	informatyka.id = 5;
	informatyka.classrooms.push_back(roominformatyka.id); // może sie odbywac tylko w pracowni informatycznej
        
        

        /* Lista nauczycieli */
	


        /* Zbyszek */    
	slimak::TimetableTeacher zbyszek;
	zbyszek.id = 0;
	zbyszek.max_slots = 10;   // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > zbyszek_poniedzialek;  // może pracowac w poniedziałek
	zbyszek_poniedzialek.push_back(0);     // na pierwszej
	zbyszek_poniedzialek.push_back(1);     // drugiej
	zbyszek_poniedzialek.push_back(2);  //  trzeciej
	zbyszek_poniedzialek.push_back(3);  // oraz czwartej lekcji
	// wtorek
	std::vector< int > zbyszek_wtorek;  // może pracowac we wtorek
	zbyszek_wtorek.push_back(0);     // na pierwszej
	zbyszek_wtorek.push_back(1);     // na drugiej 
	zbyszek_wtorek.push_back(2);  // oraz 3 lekcji
	
	std::vector< int > zbyszek_sroda;
	std::vector< int > zbyszek_czwartek;
	// slots
	zbyszek.slots.push_back( zbyszek_poniedzialek );
	zbyszek.slots.push_back( zbyszek_wtorek );
	zbyszek.slots.push_back( zbyszek_sroda );
	zbyszek.slots.push_back( zbyszek_czwartek );
	// subjcets
	zbyszek.subjects.push_back( polski.id );   // nauczyciel uczy jezyka polskiego 

	/* Lucjusz */    
	slimak::TimetableTeacher lucjusz;
	lucjusz.id = 1;
	lucjusz.max_slots = 10;   // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	std::vector< int > lucjusz_poniedzialek;
	std::vector< int > lucjusz_wtorek;  
	// sroda
	std::vector< int > lucjusz_sroda;  // może pracowac we srode
	lucjusz_sroda.push_back(0);     // na pierwszej
	lucjusz_sroda.push_back(1);     // drugiej
	lucjusz_sroda.push_back(2);  // oraz trzeciej lekcji
	// czwartek
	std::vector< int > lucjusz_czwartek;  // może pracowac we czwartek
	lucjusz_czwartek.push_back(0);     // na pierwszej
	lucjusz_czwartek.push_back(1);     // na drugiej 
	lucjusz_czwartek.push_back(2);  // oraz 3 lekcji
	// slots
	lucjusz.slots.push_back( lucjusz_poniedzialek );
	lucjusz.slots.push_back( lucjusz_wtorek );
	lucjusz.slots.push_back( lucjusz_sroda );
	lucjusz.slots.push_back( lucjusz_czwartek );
	
	// subjcets
	lucjusz.subjects.push_back( polski.id );   // nauczyciel uczy jezyka polskiego 
	
	/* Leszek */
	slimak::TimetableTeacher leszek;
	leszek.id = 2;
	leszek.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > leszek_poniedzialek;  // może pracowac w poniedziałek
	leszek_poniedzialek.push_back(0);     // na pierwszej
	leszek_poniedzialek.push_back(1);       //  na drugiej 
	leszek_poniedzialek.push_back(2);     // oraz na trzeciej lekcji
	// wtorek
	std::vector< int > leszek_wtorek;   // może pracowac we wtorek
	leszek_wtorek.push_back(0);     // na pierwszej
	leszek_wtorek.push_back(1);   // oraz na drugiej lekcji
	std::vector< int > leszek_sroda;
	std::vector< int > leszek_czwartek;
	// slots
	leszek.slots.push_back( leszek_poniedzialek );
	leszek.slots.push_back( leszek_wtorek );
	leszek.slots.push_back( leszek_sroda );
	leszek.slots.push_back( leszek_czwartek );
	// subjects
	leszek.subjects.push_back( matematyka.id );   // nauczyciel uczy matematyki 

	/* Władek */
	slimak::TimetableTeacher wladek;      
	wladek.id = 3;
	wladek.max_slots = 10;          // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	std::vector< int >wladek_poniedzialek;
	std::vector< int >wladek_wtorek;
	// sroda
	std::vector< int >wladek_sroda;  // może pracowac we srode
	wladek_sroda.push_back(0);     // na pierwszej
	wladek_sroda.push_back(1);     // drugiej
	wladek_sroda.push_back(2);  // oraz trzeciej lekcji
	// czwartek
	std::vector< int >wladek_czwartek;  // może pracowac we czwartek
	wladek_czwartek.push_back(1);     // na drugiej
	wladek_czwartek.push_back(2);     // na trzeciej 
	wladek_czwartek.push_back(3);  // oraz 4 lekcji
	wladek.slots.push_back( wladek_poniedzialek );
	wladek.slots.push_back( wladek_wtorek );
	wladek.slots.push_back( wladek_sroda );
	wladek.slots.push_back( wladek_czwartek );
	// subjects
	wladek.subjects.push_back( matematyka.id );     // nauczyciel uczy matematyki 

	
	/* Gerwazy */
	slimak::TimetableTeacher gerwazy;
	gerwazy.id = 4;
	gerwazy.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	std::vector< int > gerwazy_poniedzialek;
	// wtorek
	std::vector< int > gerwazy_wtorek;  // może pracowac we wtorek
	gerwazy_wtorek.push_back(0);     // na pierwszej
	gerwazy_wtorek.push_back(1);       //  na drugiej 
	gerwazy_wtorek.push_back(2);     // oraz na trzeciej lekcji
	// sroda
	std::vector< int > gerwazy_sroda;   // może pracowac we srode
	gerwazy_sroda.push_back(0);     // na pierwszej
	gerwazy_sroda.push_back(1);   // oraz na drugiej lekcji
	// czwartek
	std::vector< int > gerwazy_czwartek;   // może pracowac we czwartek
	gerwazy_czwartek.push_back(0);     // na pierwszej
	gerwazy_czwartek.push_back(1);   // na drugiej 
	gerwazy_czwartek.push_back(2);  //  trzeciej
	gerwazy_czwartek.push_back(3); // oraz na czwartej lekcji
	// slots
	gerwazy.slots.push_back( gerwazy_poniedzialek );
	gerwazy.slots.push_back( gerwazy_wtorek );
	gerwazy.slots.push_back( gerwazy_sroda );
	gerwazy.slots.push_back( gerwazy_czwartek );
	// subjects
	gerwazy.subjects.push_back( fizyka.id );   // nauczyciel uczy fizyki

	/* Bozydar */
	slimak::TimetableTeacher bozydar;
	bozydar.id = 5;
	bozydar.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > bozydar_poniedzialek;  // może pracowac w poniedzialek
	bozydar_poniedzialek.push_back(0);     // na pierwszej
	bozydar_poniedzialek.push_back(1);       // oraz  na drugiej lekcji
	// wtorek
	std::vector< int > bozydar_wtorek;   // może pracowac we wtorek
	bozydar_wtorek.push_back(0);     // na pierwszej
	bozydar_wtorek.push_back(1);   //  na drugiej 
	bozydar_wtorek.push_back(2);  //  trzeciej
	bozydar_wtorek.push_back(3); // oraz na czwartej lekcji
	// sroda
	std::vector< int > bozydar_sroda;   // może pracowac we srode
	bozydar_sroda.push_back(0);     // na pierwszej
	bozydar_sroda.push_back(1);   // na drugiej 
	bozydar_sroda.push_back(2);  //  trzeciej
	bozydar_sroda.push_back(3); // oraz na czwartej lekcji
	std::vector< int > bozydar_czwartek;
	// slots
	bozydar.slots.push_back( bozydar_poniedzialek );
	bozydar.slots.push_back( bozydar_wtorek );
	bozydar.slots.push_back(bozydar_sroda );
	bozydar.slots.push_back(bozydar_czwartek );
	// subjects
	bozydar.subjects.push_back( chemia.id );   // nauczyciel uczy chemii

	/* Jerzy */
	slimak::TimetableTeacher jerzy;
	jerzy.id = 6;
	jerzy.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	std::vector< int > jerzy_poniedzialek;
	std::vector< int > jerzy_wtorek;
	std::vector< int > jerzy_sroda;
	// czwartek
	std::vector< int > jerzy_czwartek;   // może pracowac we czwartek
	jerzy_czwartek.push_back(0);     // na pierwszej
	jerzy_czwartek.push_back(1);   // na drugiej 
	jerzy_czwartek.push_back(2);  //  trzeciej
	jerzy_czwartek.push_back(3); // oraz na czwartej lekcji
	// slots
	jerzy.slots.push_back( jerzy_poniedzialek);
	jerzy.slots.push_back( jerzy_wtorek);
	jerzy.slots.push_back( jerzy_sroda );
	jerzy.slots.push_back( jerzy_czwartek );
	
	// subjects
	jerzy.subjects.push_back(informatyka.id );   // nauczyciel uczy informatyki
	

	/* Wergiliusz */
	slimak::TimetableTeacher wergiliusz;
	wergiliusz.id = 7;
	wergiliusz.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > wergiliusz_poniedzialek;   // może pracowac w poniedziałek
	wergiliusz_poniedzialek.push_back(0);     // na pierwszej
	wergiliusz_poniedzialek.push_back(1);   // na drugiej 
	wergiliusz_poniedzialek.push_back(2);  //  trzeciej
	wergiliusz_poniedzialek.push_back(3); // oraz na czwartej lekcji
	std::vector< int > wergiliusz_wtorek; 
	// sroda
	std::vector< int > wergiliusz_sroda;   // może pracowac we srode
	wergiliusz_sroda.push_back(1);   // na drugiej 
	wergiliusz_sroda.push_back(2);  //  trzeciej
	wergiliusz_sroda.push_back(3); // oraz na czwartej lekcji
	std::vector< int > wergiliusz_czwartek; 
	// slots
	wergiliusz.slots.push_back( wergiliusz_poniedzialek );
	wergiliusz.slots.push_back( wergiliusz_wtorek );
	wergiliusz.slots.push_back( wergiliusz_sroda );
	wergiliusz.slots.push_back( wergiliusz_czwartek);
	
	// subjects
	wergiliusz.subjects.push_back(historia.id );   // nauczyciel uczy historii

	
	
	/* Groups */     //klasy
	// Ia
	slimak::TimetableGroup group_Ia;
	group_Ia.id = 0;
	group_Ia.subjects.push_back( polski.id );     //klasa uczy sie polskiego
	group_Ia.subjects.push_back( matematyka.id ); //  matematyki
	group_Ia.subjects.push_back(fizyka.id ); //fizyki
	group_Ia.subjects.push_back(chemia.id );  // chemii
	group_Ia.subjects.push_back( historia.id ); //historii
	group_Ia.subjects.push_back( informatyka.id ); //informatyki
	group_Ia.subjects_lessons.push_back( 2 );     // ma 2 godziny polskiego
	group_Ia.subjects_lessons.push_back( 2 );    // 2 godziny matematyki
	group_Ia.subjects_lessons.push_back( 1 ); //godzine fizyki
	group_Ia.subjects_lessons.push_back( 2 );//dwie godziny chemii
	group_Ia.subjects_lessons.push_back( 1 ); // godzine historii
	group_Ia.subjects_lessons.push_back( 2 );// 2 godziny informatyki
	// Ib
	slimak::TimetableGroup group_Ib;
	group_Ib.id = 1;
	group_Ib.subjects.push_back( polski.id );     //klasa uczy sie polskiego
	group_Ib.subjects.push_back( matematyka.id ); //  matematyki
	group_Ib.subjects.push_back(fizyka.id ); //fizyki
	group_Ib.subjects.push_back(chemia.id );  // chemii
	group_Ib.subjects.push_back( historia.id ); //historii
	group_Ib.subjects.push_back( informatyka.id ); //informatyki
	group_Ib.subjects_lessons.push_back( 2 );     // ma 2 godziny polskiego
	group_Ib.subjects_lessons.push_back( 2 );    // 2 godziny matematyki
	group_Ib.subjects_lessons.push_back( 1 ); //godzine fizyki
	group_Ib.subjects_lessons.push_back( 2 );//dwie godziny chemii
	group_Ib.subjects_lessons.push_back( 1 ); // godzine historii
	group_Ib.subjects_lessons.push_back( 2 );// 2 godziny informatyki

	/* Constraints */
	std::vector< int > puste_classrooms;
	puste_classrooms.push_back(567567);
	slimak::TimetableConstraint00 puste_ograniczenie( std::vector< int > (1, 45676 ), puste_classrooms );

	std::map< int, slimak::TimetableGroup > given_groups;
	std::map< int, slimak::TimetableTeacher > given_teachers;
	std::map< int, slimak::TimetableSubject > given_subjects;
	std::map< int, slimak::TimetableClassroom > given_classrooms;
	std::vector< slimak::TimetableConstraint * > given_constraints;

	given_groups[0] = group_Ia;
	given_groups[1] = group_Ib;
	given_teachers[0] = zbyszek;
	given_teachers[1] = lucjusz;
	given_teachers[2] = leszek;
	given_teachers[3] = wladek;
	given_teachers[4] = gerwazy;
	given_teachers[5] = bozydar;
	given_teachers[6] = jerzy;
	given_teachers[7] = wergiliusz;
	given_subjects[0] = polski;
	given_subjects[1] = matematyka;
	given_subjects[2] = fizyka;
	given_subjects[3] = historia;
	given_subjects[4] = chemia;
	given_subjects[5] = informatyka;
	given_classrooms[1] = room001;
	given_classrooms[2] = room002;
	given_classrooms[3] = room003;
	given_classrooms[4] = roomchemia;
	given_classrooms[5] = roominformatyka;
	given_constraints.push_back( &puste_ograniczenie );

	int liczba_dni = 4;   // liczba dni  i liczba godzin 
	int liczba_godzin  = 4;

	slimak::TimetableGenerator generator (
		 liczba_dni, liczba_godzin, 
		given_groups, given_teachers, given_subjects, given_classrooms, given_constraints
	);
	
	slimak::TimetablePlan plan_Ia = generator.generateForGroup ( group_Ia );

	slimak::TimetablePlan plan_Ib = generator.generateForGroup ( group_Ib );

	std::cerr << "Plan Ia" << std::endl;
	for (int day = 0; day < liczba_dni; ++day) {
		std::cerr << "Day " << day << ":" << std::endl;
		for (int slot = 0; slot < liczba_godzin; ++slot ) {
			std::cerr << "- Slot " << slot << ": ";
			if ( plan_Ia.slots[day][slot].isEmpty()
				|| plan_Ia.slots[day][slot].isBlank() ) {
					std::cerr << " --- " << std::endl;
					continue;
			}
			std::cerr << plan_Ia.slots[day][slot].teacher.id << " ";
			std::cerr << plan_Ia.slots[day][slot].subject.id << " ";
			std::cerr << plan_Ia.slots[day][slot].classroom.id << std::endl;
		}
	}

	std::cerr << "\nPlan Ib" << std::endl;
	for (int day = 0; day < liczba_dni; ++day) {
		std::cerr << "Day " << day << ":" << std::endl;
		for (int slot = 0; slot < liczba_godzin; ++slot ) {
			std::cerr << "- Slot " << slot << ": ";
			if ( plan_Ib.slots[day][slot].isEmpty()
				|| plan_Ib.slots[day][slot].isBlank() ) {
					std::cerr << " --- " << std::endl;
					continue;
			}
			std::cerr << plan_Ib.slots[day][slot].teacher.id << " ";
			std::cerr << plan_Ib.slots[day][slot].subject.id << " ";
			std::cerr << plan_Ib.slots[day][slot].classroom.id << std::endl;
		}
	}

	return 0;

}
