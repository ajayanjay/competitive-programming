#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

int main(void) {

	ll n, m;

	scanf("%lld %lld", &n, &m);

	bool skipped_line[m];
	for (ll i = 0; i < m; ++i)
		skipped_line[i] = false;	

	if (n != 1) {

		ll old_size;
		scanf("%lld", &old_size);
		ll old_record[m];

		for (ll i = 0; i < old_size; ++i)
			scanf(" %lld", &old_record[i]);

		for (ll i = 1; i < n; ++i) {
			ll curr_size;
			scanf("%lld", &curr_size);

 			ll curr_record[curr_size];
			for (ll j = 0; j < curr_size; ++j)
				scanf(" %lld", &curr_record[j]);

			ll last_person_index = 0;

			while (last_person_index < curr_size && curr_record[last_person_index] != old_record[old_size - 1])
				last_person_index++;

			if (last_person_index != curr_size && curr_size > 1) {
				ll old_person_index = old_size - 1 - 1;
				ll curr_person_index = last_person_index - 1;
				while (old_person_index >= 0 && curr_person_index >= 0) {
					ll old_queue_person = old_record[old_person_index];
					ll curr_queue_person = curr_record[curr_person_index];

					// found someone who cuts the line!
					if (old_queue_person != curr_queue_person) {
						skipped_line[curr_queue_person - 1] = true;
						curr_person_index--;
					} else {
						curr_person_index--;
						old_person_index--;
					}
				}

				while (curr_person_index >= 0)
					skipped_line[curr_record[curr_person_index--] - 1] = true;
			}

			old_size = curr_size;
			for (ll j = 0; j < curr_size; ++j)
				old_record[j] = curr_record[j];
		}
	} 

	for (ll i = 0; i < m; ++i)
		printf("%d ", skipped_line[i]);

	return 0;
}