#pragma once

namespace FlowControl { class Manipulate; }

namespace state {
	namespace detail {
		template <CardType CardType, CardZone CardZone>
		struct InvokeCallback {
			static void Added(FlowControl::Manipulate const& manipulate, state::State & state, state::CardRef card_ref) {}
			static void Removed(FlowControl::Manipulate const& manipulate, state::State & state, state::CardRef card_ref) {}
		};

		template <CardType CardType>
		struct InvokeCallback<CardType, kCardZonePlay> {
			static void Added(FlowControl::Manipulate const& manipulate, state::State & state, state::CardRef card_ref) {}
			static void Removed(FlowControl::Manipulate const& manipulate, state::State & state, state::CardRef card_ref) {}
		};

		template <CardType CardType>
		struct InvokeCallback<CardType, kCardZoneHand> {
			static void Added(FlowControl::Manipulate const& manipulate, state::State & state, state::CardRef card_ref) {}
			static void Removed(FlowControl::Manipulate const& manipulate, state::State & state, state::CardRef card_ref) {}
			static void Removed(FlowControl::Manipulate const& manipulate, state::Events::Manager & event_mgr, state::CardRef card_ref) {}
		};
	}
}
