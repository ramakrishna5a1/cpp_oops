#include <iostream>

namespace gears
{
	const int neutral = -1;
	namespace car
	{
		const int max_gears = 5;
	}

	namespace lorry
	{
		const int max_gears = 6;
	}
}


namespace acceleration
{
	
}

class vehicle
{
	protected:
		int num_of_wheels;
        	int gear_position;
        
	public:
		virtual bool change_acceleration(const int acceleration_speed) = 0;
		virtual int current_gear_position() = 0;
		virtual bool change_gear_position(const int gear_num) = 0;
		virtual bool change_steer_direction(const float degrees,int direction) = 0;
		virtual void vehicle_type() = 0;
};

class car : public vehicle
{
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
   	vehicle *veh_car = new car(); 
	veh_car->change_gear_position(10);
	
	vehicle &v = *veh_car;
	std::cout<<v.current_gear_position()<<std::endl;	
	return 0;
}



