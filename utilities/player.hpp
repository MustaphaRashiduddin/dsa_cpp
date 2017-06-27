#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <ostream>

struct player {
        int id;
        std::string name;
        int score;

        player(int id, std::string name, int score) : id{id}, name{name}, score{score} { }
        friend std::ostream& operator<< (std::ostream& out, const player& p) { return out << p.id << "; " << p.name << "; " << p.score << " |"; }
        int getid() { return id; }
};

#endif
