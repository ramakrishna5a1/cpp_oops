class vehicle
{
        protected:
                int num_of_wheels;
                int gear_position;
                float steer_position;

        public:
                virtual bool change_acceleration(const int acceleration_speed) = 0;
                virtual int current_gear_position() = 0;
                virtual bool change_gear_position(const int gear_num) = 0;
                virtual bool change_steer_direction(const float degrees,int direction) = 0;
                virtual void vehicle_type() = 0;
};

