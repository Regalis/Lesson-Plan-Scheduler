/* Test code */

#include <iostream>
#include "TimetableGenerator.hpp"

int main() {

	/* Rooms */
	slimak::TimetableClassroom room001;
	room001.id = 1;
	room001.capacity = 20;
	slimak::TimetableClassroom room005;
	room005.id = 5;
	room005.capacity = 50;
	
	/* Subjects */
	// polski
	slimak::TimetableSubject polski;
	polski.id = 0;
	polski.fatigue_level = 1;
	polski.classrooms.push_back(room001.id);
	polski.classrooms.push_back(room005.id);
	// matematyka
	slimak::TimetableSubject matematyka;
	matematyka.id = 1;
	matematyka.fatigue_level = 1;
	matematyka.classrooms.push_back(room005.id);

	/* Zbyszek */
	slimak::TimetableTeacher zbyszek;
	zbyszek.id = 0;
	zbyszek.max_slots = 10;
	// poniedzialek
	std::vector< int > zbyszek_poniedzialek;
	zbyszek_poniedzialek.push_back(0);
	zbyszek_poniedzialek.push_back(1);
	// wtorek
	std::vector< int > zbyszek_wtorek;
	zbyszek_wtorek.push_back(0);
	zbyszek_wtorek.push_back(1);
	// slots
	zbyszek.slots.push_back( zbyszek_poniedzialek );
	zbyszek.slots.push_back( zbyszek_wtorek );
	// subjcets
	zbyszek.subjects.push_back( polski.id );
	
	/* Leszek */
	slimak::TimetableTeacher leszek;
	leszek.id = 1;
	leszek.max_slots = 10;
	// poniedzialek
	std::vector< int > leszek_poniedzialek;
	leszek_poniedzialek.push_back(0);
	leszek_poniedzialek.push_back(1);
	leszek_poniedzialek.push_back(2);
	// wtorek
	std::vector< int > leszek_wtorek;
	// slots
	leszek.slots.push_back( leszek_poniedzialek );
	leszek.slots.push_back( leszek_wtorek );
	// subjects
	leszek.subjects.push_back( matematyka.id );

	/* Władek */
	slimak::TimetableTeacher wladek;
	wladek.id = 2;
	wladek.max_slots = 10;
	// poniedzialek
	std::vector< int > wladek_poniedzialek;
	wladek_poniedzialek.push_back(2);
	// wtorek
	std::vector< int > wladek_wtorek;
	wladek_wtorek.push_back(2);
	// slots
	wladek.slots.push_back( wladek_poniedzialek );
	wladek.slots.push_back( wladek_wtorek );
	// subjects
	wladek.subjects.push_back( matematyka.id );
	
	/* Groups */
	// Ia
	slimak::TimetableGroup group_Ia;
	group_Ia.id = 0;
	group_Ia.teacher_id = 2;
	group_Ia.subjects.push_back( polski.id );
	group_Ia.subjects.push_back( matematyka.id );
	group_Ia.subjects_lessons.push_back( 2 );
	group_Ia.subjects_lessons.push_back( 2 );
	// Ib
	slimak::TimetableGroup group_Ib;
	group_Ib.id = 1;
	group_Ib.teacher_id = 1;
	group_Ib.subjects.push_back( polski.id );
	group_Ib.subjects.push_back( matematyka.id );
	group_Ib.subjects_lessons.push_back( 2 );
	group_Ib.subjects_lessons.push_back( 2 );

	/* Constraints */
	std::vector< int > zbyszek_classrooms;
	zbyszek_classrooms.push_back(1);
	slimak::TimetableConstraint00 zbyszek_w_001( std::vector< int > (1, zbyszek.id ), zbyszek_classrooms );

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

	slimak::TimetableGenerator generator (
		2, 3,
		given_groups, given_teachers, given_subjects, given_classrooms, given_constraints
	);
	
	slimak::TimetablePlan plan_Ia = generator.generateForGroup ( group_Ia );

	std::cerr << "Plan Ia" << std::endl;
	for (int day = 0; day < 2; ++day) {
		std::cerr << "Day " << day << ":" << std::endl;
		for (int slot = 0; slot < 3; ++slot ) {
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

	slimak::TimetablePlan plan_Ib = generator.generateForGroup ( group_Ib );
	
	std::cerr << "\nPlan Ib" << std::endl;
	for (int day = 0; day < 2; ++day) {
		std::cerr << "Day " << day << ":" << std::endl;
		for (int slot = 0; slot < 3; ++slot ) {
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
