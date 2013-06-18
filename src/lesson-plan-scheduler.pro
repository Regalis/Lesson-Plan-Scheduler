######################################################################
# Lesson Plan Scheduler
######################################################################

TEMPLATE = app
TARGET = lesson-plan-scheduler
INCLUDEPATH += . ./csp

# Input
HEADERS += ClassroomsProps.hpp LessonPlanScheduler.hpp MainWindow.hpp Subjects.hpp Timetable.hpp
SOURCES += ClassroomsProps.cpp LessonPlanScheduler.cpp main.cpp MainWindow.cpp Subjects.cpp Timetable.cpp

# CSP
HEADERS += ./csp/CSP.hpp ./csp/CSPAttribute.hpp ./csp/CSPColor.hpp ./csp/CSPConstraint.hpp ./csp/CSPVariable.hpp ./csp/Graph.hpp ./csp/TimetableAttribute.hpp ./csp/TimetableColor.hpp ./csp/TimetableConstraint.hpp ./csp/TimetableConstraints.hpp ./csp/TimetableGenerator.hpp ./csp/TimetableStructures.hpp

SOURCES += ./csp/CSP.cpp ./csp/CSPAttribute.cpp ./csp/CSPColor.cpp ./csp/TimetableAttribute.cpp ./csp/TimetableColor.cpp ./csp/TimetableConstraint.cpp ./csp/TimetableConstraints.cpp ./csp/TimetableGenerator.cpp
./csp/

QT += widgets sql
