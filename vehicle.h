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

namespace steer_direction
{
        const int left = -1;
        const int right = 1;
}

namespace acceleration
{
}


class vehicle
{
        protected:
                int num_of_wheels;
                int gear_position;
                float steer_position;

        public:
		vehicle(int num_of_wheels)
		{
			this->num_of_wheels = num_of_wheels;
			gear_position = gears::neutral;
			steer_position = 0;
		}

                virtual bool change_acceleration(const int acceleration_speed) = 0;
                virtual int current_gear_position() = 0;
                virtual bool change_gear_position(const int gear_num) = 0;
                virtual bool change_steer_direction(const float degrees,int direction) = 0;
                virtual void vehicle_type() = 0;
};

