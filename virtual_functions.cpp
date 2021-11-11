#include "vehicle.h"
#include <iostream>


class car : public vehicle
{
	public:
		car(int num_of_wheels) : vehicle(num_of_wheels)
		{
	
		}

	virtual bool change_acceleration(const int acceleration) override
	{
		if(gear_position == gears::neutral)
		{
			std::cout<<"unable to accelerate gear is in neutral."<<std::endl;
			return false;
		}
		else
		{	
			return true;	
		}
	}

    	virtual bool change_gear_position(const int gear_num) override
    	{
		if(gear_num == gear_position)
		{
			return false;
		}
		else if(gear_num == gears::neutral)
		{
			std::cout<<"gear is set to neutral."<<std::endl;
			return true;	
		}
		else if(gear_num <= gears::car::max_gears)
		{
			gear_position = gear_num;
			std::cout<<"gear changed to: "+std::to_string(gear_position)<<std::endl;
			return true;
		}
		else
		{
			std::cout<<"invalid gear\n";
			return true;
		}
    	}
    	
    	virtual int current_gear_position() override
    	{
        	return gear_position;
    	}
    
	virtual bool change_steer_direction(const float degrees,const int direction) override
	{
		if(gear_position != gears::neutral)
		{
			steer_position = steer_position + (float)(degrees * direction);
			return true;
		}
		else
		{
			return false;	
		}
	}


	virtual void vehicle_type()
	{
		std::cout<<"vehicle type is: "<<"car\n";
	}

	//virtual destructor as virtual functions are used
	virtual ~car()
	{
		
	}
};

class lorry : protected vehicle
{

};


int main()
{
	/*
	 * Here memory is allocated on Heap for car class and that memory reference is holding by the stack variable 
	 * which is a pointer variable
	 * */

	vehicle *veh_car = new car(6);
	veh_car->change_gear_position(10);
	
	return 0;
}



