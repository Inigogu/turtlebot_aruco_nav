#!/usr/bin/env python3

class PID():
    def __init__(self, target, kp, ki, kd, min_val, max_val):
        # Initiate target and PID gains 
        self.target = target
        self.kp = kp
        self.ki = ki
        self.kd = kd

        # Set min_val and max_val values of output for controller
        self.min_val = min_val
        self.max_val = max_val

        # Initiate delta_time and prev arguments
        self.delta_time = 0.0
        self.prev_error = 0.0
        self.prev_value = 0.0
        self.prev_time = 0.0

        # Initiate integrator and differentiator
        self.integrator = 0.0
        self.differentiator = 0.0

    def calculate_error(self, current_value):
        return self.target - current_value

    def calculate_delta_time(self, current_time):
        self.delta_time = current_time - self.prev_time 
        self.prev_time = current_time

    def calculate_p(self, error):
        return self.kp * error

    def calculate_i(self, error, delta_time):
        self.integrator += error * delta_time
        # TODO: Anti Wind-up module for integrator
        # TODO: Saturate min_val and max_val value of integrator
        return self.ki * self.integrator

    def calculate_d(self, error, delta_time):
        self.differentiator = (error - self.prev_error) / delta_time
        return self.kd * self.differentiator 

    def calculate_current_PID_gains(self, current_value, current_time):
        # Calculate error and delta_time
        error = self.calculate_error(current_value)
        self.calculate_delta_time(current_time)

        # Calculate PID values
        proportional = self.calculate_p(error)
        integral = self.calculate_i(error, self.delta_time)
        derivative = self.calculate_d(error, self.delta_time)
        pid = proportional + integral + derivative

        # Assign current error and value to previous
        self.prev_error = error
        self.prev_value = current_value

        # Limit output to min_val and max_val range of values
        if pid > self.max_val:
            pid = self.max_val
        elif pid < self.min_val:
            pid = self.min_val
        return pid