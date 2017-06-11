#pragma once

#include <iostream>

#include "MCTS/Config.h"

namespace mcts
{
	namespace detail
	{
		template <bool enabled = mcts::StaticConfigs::enable_statistic>
		class Statistic {
		public:
			void ApplyActionSucceeded() {}
			void ApplyActionFailed() {}
			void FinishedOneEpisode() {}
			void PrintMessage() {}
		};

		template <> class Statistic<true>
		{
		public:
			Statistic() :
				apply_action_success_(0), apply_action_total_(0), episode_(0)
			{}

			void ApplyActionSucceeded() {
				apply_action_success_++;
				apply_action_total_++;
			}
			void ApplyActionFailed() {
				apply_action_total_++;
			}

			void FinishedOneEpisode() {
				episode_++;
			}

			void PrintMessage() {
				double apply_action_success_rate = 0.0;
				if (apply_action_total_ > 0) {
					apply_action_success_rate = (int)(apply_action_success_ * 100 / apply_action_total_);
				}

				std::cout << "====== Statistics =====" << std::endl;
				std::cout << "Total episodes: " << episode_ << std::endl;
				std::cout << "Apply action success rate: "
					<< apply_action_success_ << " / " << apply_action_total_
					<< " (" << apply_action_success_rate << "%) "
					<< std::endl;
			}

		private:
			int apply_action_success_;
			int apply_action_total_;
			int episode_;
		};
	}
}