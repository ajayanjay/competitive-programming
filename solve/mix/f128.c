#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int total_length, t, k, velocity;

	scanf("%d %d %d %d", &total_length, &t, &k, &velocity);

	double lambda;
	scanf("%lf", &lambda);
	double vel = velocity;

	int start_pos = k;
	bool direction = true; // true -> right false -> left

	double particle_pos = k;

	double time = t;

	while ((start_pos + vel * time) > total_length) { // if hits wall

		// decrease time by start pos
		time -= (total_length - start_pos) / vel;

		// multiply velocity by lambda
		vel *= lambda;

		// reset start pos to 0
		start_pos = 0;

		// switch direction
		direction = !direction;

		particle_pos = direction ? 0 : total_length;
	}

	if (direction) {
		particle_pos += (time * vel);
	} else {
		particle_pos -= (time * vel);
	}

	printf("%.10lf", particle_pos);
	return 0;
}