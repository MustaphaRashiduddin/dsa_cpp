#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <ostream>

class player {
        private: 
                int id;
                std::string name;
                int score;

        public:
                player(int id, std::string name, int score) : id{id}, name{name}, score{score} { }
                friend std::ostream& operator<< (std::ostream& out, const player& p) {
                        return out << p.id << " | " << p.name << " | " << p.score << ".";
                }
};

#endif
