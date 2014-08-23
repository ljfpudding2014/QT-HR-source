#ifndef  _H_CREATETABLE
#define  _H_CREATETABLE


#include <qstring.h>


#define TEACHERSTR "CREATE TABLE IF NOT EXISTS `qtdb`.`teacher` ("\
                   "`teacher_id` INT NOT NULL,"\
                   "`teacher_name` VARCHAR(45) NULL,"\
                   "`teacher_phone` VARCHAR(45) NULL,"\
                   "`teachercol` VARCHAR(45) NULL,"\
                   "PRIMARY KEY (`teacher_id`))"\
                   "ENGINE = InnoDB"					

#define  COURSESTR  "CREATE TABLE IF NOT EXISTS `qtdb`.`Course` ("\
                  "`Course_id` INT NOT NULL,"\
                  "`Course_name` VARCHAR(45) NULL,"\
                  "`Course_grade` VARCHAR(45) NOT NULL,"\
                  "`Course_rev` VARCHAR(45) NULL,"\
                  "PRIMARY KEY (`Course_id`, `Course_grade`))"\
                  "ENGINE = InnoDB"				  
				  
#define  CLASSSTR "CREATE TABLE IF NOT EXISTS `qtdb`.`class` (`class_id` INT NOT NULL,`class_name` VARCHAR(45) NULL,`class_grade` VARCHAR(45) NULL, PRIMARY KEY (`class_id`)) ENGINE = InnoDB"
				  
#define	STUDSTR  "CREATE TABLE IF NOT EXISTS `qtdb`.`student` (`student_id` INT NOT NULL,  `student_name` VARCHAR(45) NULL,  `student_phone` VARCHAR(45) NULL,  `student_age` INT NULL,  `student_gender` INT NULL,  `student_home` VARCHAR(45) NULL,  `class_class_id` INT NOT NULL,  PRIMARY KEY (`student_id`),  INDEX `fk_student_class1_idx` (`class_class_id` ASC),  CONSTRAINT `fk_student_class1`    FOREIGN KEY (`class_class_id`)    REFERENCES `qtdb`.`class` (`class_id`)    ON DELETE NO ACTION    ON UPDATE NO ACTION) ENGINE = InnoDB" 
                 
				  
#define COURSEHASTEACHERSTR  "CREATE TABLE IF NOT EXISTS `qtdb`.`Course_has_teacher` (  `Course_Course_id` INT NOT NULL,  `Course_Course_grade` VARCHAR(45) NOT NULL,  `teacher_teacher_id` INT NOT NULL,  `Course_has_teacher_time` VARCHAR(45) NULL,  `Course_has_teacher_classroom` VARCHAR(45) NULL,  PRIMARY KEY (`Course_Course_id`, `Course_Course_grade`, `teacher_teacher_id`),  INDEX `fk_Course_has_teacher_teacher1_idx` (`teacher_teacher_id` ASC),  INDEX `fk_Course_has_teacher_Course_idx` (`Course_Course_id` ASC, `Course_Course_grade` ASC),  CONSTRAINT `fk_Course_has_teacher_Course`    FOREIGN KEY (`Course_Course_id` , `Course_Course_grade`)    REFERENCES `qtdb`.`Course` (`Course_id` , `Course_grade`)    ON DELETE NO ACTION    ON UPDATE NO ACTION,  CONSTRAINT `fk_Course_has_teacher_teacher1`    FOREIGN KEY (`teacher_teacher_id`)    REFERENCES `qtdb`.`teacher` (`teacher_id`)    ON DELETE NO ACTION    ON UPDATE NO ACTION) ENGINE = InnoDB"
				  
#define STUDHASCOURSESTR  "CREATE TABLE IF NOT EXISTS `qtdb`.`student_has_Course` (  `student_student_id` INT NOT NULL,  `Course_Course_id` INT NOT NULL,  `Course_Course_grade` VARCHAR(45) NOT NULL,  PRIMARY KEY (`student_student_id`, `Course_Course_id`, `Course_Course_grade`),  INDEX `fk_student_has_Course_Course1_idx` (`Course_Course_id` ASC, `Course_Course_grade` ASC),  INDEX `fk_student_has_Course_student1_idx` (`student_student_id` ASC),  CONSTRAINT `fk_student_has_Course_student1`    FOREIGN KEY (`student_student_id`)    REFERENCES `qtdb`.`student` (`student_id`)    ON DELETE NO ACTION    ON UPDATE NO ACTION,  CONSTRAINT `fk_student_has_Course_Course1`    FOREIGN KEY (`Course_Course_id` , `Course_Course_grade`)    REFERENCES `qtdb`.`Course` (`Course_id` , `Course_grade`)    ON DELETE NO ACTION    ON UPDATE NO ACTION) ENGINE = InnoDB"	  
				  
class InitDBTableStringObj
{
public:
    InitDBTableStringObj()
    {
        m_TeacherStr = QString(TEACHERSTR);
        m_CourseStr = QString(COURSESTR);
        m_ClassStr = QString(CLASSSTR);
	m_StudStr = QString(STUDSTR);
        m_CourceHasTeacherStr = QString(COURSEHASTEACHERSTR);
        m_StudentHasCourceStr = QString(STUDHASCOURSESTR);
    }
	
    ~InitDBTableStringObj(){}


private:
    QString m_StudStr;
    QString m_CourseStr;
    QString m_TeacherStr;
    QString m_ClassStr;
    QString m_CourceHasTeacherStr;
    QString m_StudentHasCourceStr;


  public:
    QString & GetStudentSQL(){return m_StudStr;}
    QString & GetCourseSQL(){return m_CourseStr;}
    QString & GetTeacherSQL(){return m_TeacherStr;}
    QString & GetClassSQL(){return m_ClassStr;}
    QString & GetCourseHasTeacherSQL(){return m_CourceHasTeacherStr;}
    QString & GetStudentHasCourseSQL(){return m_StudentHasCourceStr;}

};


class Student
{
public:
    Student()
    {



    }
    ~Student()
    {

    }


public:

    QString CreateStudTable()
    {

    }


private:



};








#endif	_H_CREATETABLE
