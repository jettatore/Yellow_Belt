#include<iostream>
#include<string>
#include<map>

using namespace std;

// ������������ ��� ��� ������� ������
enum class TaskStatus {
	NEW,          // �����
	IN_PROGRESS,  // � ����������
	TESTING,      // �� ������������
	DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// �������� ���������� �� �������� ����� ����������� ������������
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return tasks.at(person);
	};

	// �������� ����� ������ (� ������� NEW) ��� ����������� �������������
	void AddNewTask(const string& person) {
		tasks[person][TaskStatus::NEW]++;

	};

	// �������� ������� �� ������� ���������� ����� ����������� ������������,
	// ����������� ��. ����
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		TasksInfo updated;
		TasksInfo untoched;
		TasksInfo temp = tasks[person];
		map<TaskStatus, int>::iterator it = temp.begin();
		while (task_count > 0||it!=temp.end()) {
			auto it_pair = *it;
			int it_value = it_pair.second;
			task_count -= it_value;
			if (task_count >= 0) {
				auto it_updated = ++it;
				--it;
				auto task_status = *it_updated;
				updated[task_status.first] = it_value;
			}
			else {
				auto it_updated = ++it;
				--it;
				auto task_status = *it_updated;
				updated[task_status.first] = it_value + task_count;
				untoched[it_pair.first] = (-1)*task_count;
			}
			it++;
		}
		return make_pair(updated, untoched);
	};

	map<string, TasksInfo>tasks;
};

// ��������� ������� �� ��������, ����� ����� �����������
// ���������� � ������������� ������ � ������� [] � �������� 0,
// �� ����� ��� ���� �������� �������
void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		" and " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
	TeamTasks tasks;
	tasks.AddNewTask("Ilia");
	for (int i = 0; i < 3; ++i) {
		tasks.AddNewTask("Ivan");
	}
		
	cout << "Ilia's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
		
	TasksInfo updated_tasks, untouched_tasks;

	
	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);
	

	return 0;
}