#pragma once

#include <string>
#include <vector>
#include <set>
#include <map>


class tag
{
public:
    enum priority
    {
        ultraLow = -2,
        Low,
        Middle,
        Hight,
        ultraHight
    };

    // Конструктор с максимум параметров, все приводят к нему
    tag(std::string tag_name, std::string tag_description, priority tag_p) : name(tag_name), description(tag_description), p(tag_p)
    {
        last_id++;
        id = last_id;
    }                            //  вызывается ^^^^^^^^^^^^
    tag(std::string tag_name, std::string tag_description) : tag(tag_name, tag_description, tag::priority::Middle)
    {
    }
    tag(std::string tag_name) : tag(tag_name, "_empty_", tag::priority::Middle)
    {
    }
    tag() : tag("_none_", "_empty_", tag::priority::Middle)
    {
    }
    //конструктор копирования если надо будет выделять память динамически
    tag(const tag& object)
    {
        name = object.name;
        description = object.description;
        p = object.p;
        id = object.id;
    }
    /**************************** перегрузка операторов < > == (по умному полиморфизм) ******************************/
    //оператор сравнения по приоритетам
    bool operator<(const tag& other) const
    {
        if (p < other.GetPriority())
            return true;
        else
            return id < other.GetId();
    }
    //оператор сравнения по приоритетам
    bool operator>(const tag& other) const
    {
        if (p > other.GetPriority())
            return true;
        else
            return id > other.GetId();
    }
    //оператор сравнения по id (быстрее чем сравнивать строку и можно сделать несколько названий с 1 id)
    bool operator==(const tag& other) const
    {
        return id == other.GetId();
    }
    /**************************** взаимодействие со скрытыми членами (по умному инкапсуляция) ******************************/
    //
    int GetId() const
    {
        return id;
    }
    int& Id()
    {
        return id;
    }
    void SetId(int new_id)
    {
        id = new_id;
    }

    priority GetPriority() const
    {
        return p;
    }
    priority& Priority()
    {
        return p;
    }
    void SetPriority(priority new_p)
    {
        p = new_p;
    }

    std::string Name()
    {
        return name;
    }

    std::string Description()
    {
        return description;
    }
    /**************************** методы ******************************/
    //для вывода
    std::string to_string()
    {
        return "[" + std::to_string(id) + "]{" + std::to_string((int)p) + "}\t" + name + " (" + description + ")";
    }

private:
    std::string name;
    std::string description;
    int id;
    priority p;
    static int last_id;
};




class tags
{
public:
    //добавление тега
    bool AddTag(tag new_tag)
    {
        if (CheckTag(new_tag))
            return false;
        else
            tag_list.insert(new_tag);
        return true;
    }
    //проверка наличия тега
    bool CheckTag(tag checking_tag)
    {
        for (auto tag_ptr : tag_list)
            if (tag_ptr == checking_tag)
                return true;
        return false;
    }
    //поиск тега
    tag FindTag(tag checking_tag)
    {

        return *tag_list.find(checking_tag);
    }
    //поиск тега и его удаление
    tag GetTag(tag checking_tag)
    {
        tag tmp = *tag_list.find(checking_tag);
        tag_list.erase(tmp);
        return tmp;
    }
    //очистка всего тега
    void Clear()
    {
        tag_list.clear();
    }
private:
    std::set<tag> tag_list;
};
