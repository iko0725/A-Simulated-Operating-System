#ifndef H_GV_H
#define H_GV_H
#include <QString>
#include "vector"
#include <QDialog>
#include <QVector>

extern bool flag_login;
extern QString login_username;
//extern std::vector<bool> flags;
//extern std::vector<QDialog*> dlgs;
struct Task{
   QString  task_name;
   int   memory_size;

};


extern std::vector<Task> allocate_memory;
extern std::vector<bool> flags;
extern std::vector<QDialog*> dlgs;
extern std::vector<QWidget*> wids;
extern std::vector<int> process;
extern int memory_percent;
#endif // H_GV_H
