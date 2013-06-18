/* Test code */

#include <iostream>
#include "TimetableGenerator.hpp"

int main() {

	/* Rooms */ // okresla liczbę dostępnych sal oraz ilosc miejsc w salach. W tym przypadku mamy 2 dostępne sale 001 i 005
	slimak::TimetableClassroom room001; //numer sali - 001
	room001.id = 1;
	room001.capacity = 20;              //ilosc miejsc w sali 001- 20
	slimak::TimetableClassroom room005;  //numer sali - 005
	room005.id = 5;
	room005.capacity = 50;    //ilosc miejsc w sali 005- 50
	
	/* Subjects */    // lista przedmiotów
	// polski
	slimak::TimetableSubject polski;  // język polski
	polski.id = 0;
	polski.classrooms.push_back(room001.id);  // moze sie odbywać w salach 001 oraz oo5
	polski.classrooms.push_back(room005.id);
	// matematyka
	slimak::TimetableSubject matematyka;  // matematyka
	matematyka.id = 1;
	matematyka.classrooms.push_back(room005.id); // może sie odbywac tylko w sali 005
        

        /* Lista nauczycieli */
	


        /* Zbyszek */    
	slimak::TimetableTeacher zbyszek;
	zbyszek.id = 0;
	zbyszek.max_slots = 10;   // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > zbyszek_poniedzialek;  // może pracowac w poniedziałek
	zbyszek_poniedzialek.push_back(0);     // na pierwszej
	zbyszek_poniedzialek.push_back(1);   // oraz na drugiej lekcji
	// wtorek
	std::vector< int > zbyszek_wtorek;  // może pracowac we wtorek
	zbyszek_wtorek.push_back(0);     // na pierwszej
	zbyszek_wtorek.push_back(1);     // oraz na drugiej lekcji
	// slots
	zbyszek.slots.push_back( zbyszek_poniedzialek );
	zbyszek.slots.push_back( zbyszek_wtorek );
	// subjcets
	zbyszek.subjects.push_back( polski.id );   // nauczyciel uczy jezyka polskiego 
	
	/* Leszek */
	slimak::TimetableTeacher leszek;
	leszek.id = 1;
	leszek.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > leszek_poniedzialek;  // może pracowac w poniedziałek
	leszek_poniedzialek.push_back(0);     // na pierwszej
	leszek_poniedzialek.push_back(1);       //  na drugiej 
	leszek_poniedzialek.push_back(2);     // oraz na trzeciej lekcji
	// wtorek
	std::vector< int > leszek_wtorek;   // nie moze pracowac we wtorek (ilosc godzin 0)
	// slots
	leszek.slots.push_back( leszek_poniedzialek );
	leszek.slots.push_back( leszek_wtorek );
	// subjects
	leszek.subjects.push_back( matematyka.id );   // nauczyciel uczy matematyki 

	/* Władek */
	slimak::TimetableTeacher wladek;      
	wladek.id = 2;
	wladek.max_slots = 10;          // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > wladek_poniedzialek;   // może pracowac w poniedziałek
	wladek_poniedzialek.push_back(2);    // tylko na trzeciej lekcji
	// wtorek
	std::vector< int > wladek_wtorek;    // może pracowac we wtorek
	wladek_wtorek.push_back(2);         // tylko na trzeciej lekcji
	// slots
	wladek.slots.push_back( wladek_poniedzialek );
	wladek.slots.push_back( wladek_wtorek );
	// subjects
	wladek.subjects.push_back( matematyka.id );     // nauczyciel uczy matematyki 
	
	/* Groups */     //klasy
	// Ia
	slimak::TimetableGroup group_Ia;
	group_Ia.id = 0;
	group_Ia.subjects.push_back( polski.id );     //klasa uczy sie polskiego
	group_Ia.subjects.push_back( matematyka.id ); // oraz matematyki
	group_Ia.subjects_lessons.push_back( 2 );     // ma 2 godziny polskiego
	group_Ia.subjects_lessons.push_back( 2 );    //oraz 2 godziny matematyki
	// Ib
	slimak::TimetableGroup group_Ib;
	group_Ib.id = 1;
	group_Ib.subjects.push_back( polski.id );    //klasa uczy sie polskiego
	group_Ib.subjects.push_back( matematyka.id );   // oraz matematyki
	group_Ib.subjects_lessons.push_back( 2 );     // ma 2 godziny polskiego
	group_Ib.subjects_lessons.push_back( 2 );      //oraz 2 godziny matematyki

	/* Constraints */
	std::vector< int > zbyszek_classrooms;
	zbyszek_classrooms.push_back(567567);
	slimak::TimetableConstraint00 zbyszek_w_001( std::vector< int > (1, 45676 ), zbyszek_classrooms );

	std::map< int, slimak::TimetableGroup > given_groups;
	std::map< int, slimak::TimetableTeacher > given_teachers;
	std::map< int, slimak::TimetableSubject > given_subjects;
	std::map< int, slimak::TimetableClassroom > given_classrooms;
	std::vector< slimak::TimetableConstraint * > given_constraints;

	given_groups[0] = group_Ia;
	given_groups[1] = group_Ib;
	given_teachers[0] = zbyszek;
	given_teachers[1] = leszek;
	given_teachers[2] = wladek;
	given_subjects[0] = polski;
	given_subjects[1] = matematyka;
	given_classrooms[1] = room001;
	given_classrooms[5] = room005;
	given_constraints.push_back( &zbyszek_w_001 );

	int liczba_dni = 2;   // liczba dni  i liczba godzin 
	int liczba_godzin  = 3;

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
