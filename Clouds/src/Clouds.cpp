#include "plugin.hpp"


struct Clouds : Module {
	enum ParamId {
		_1X2_PARAM,
		GAIN1_PARAM,
		GAIN2_PARAM,
		TRIG_PARAM,
		TIME_PARAM,
		OFST1_PARAM,
		OFST2_PARAM,
		THERS_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN1_INPUT,
		IN2_INPUT,
		TRIG_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUT1_OUTPUT,
		OUT2_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	Clouds() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(_1X2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(GAIN1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(GAIN2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(TRIG_PARAM, 0.f, 1.f, 0.f, "");
		configParam(TIME_PARAM, 0.f, 1.f, 0.f, "");
		configParam(OFST1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(OFST2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(THERS_PARAM, 0.f, 1.f, 0.f, "");
		configInput(IN1_INPUT, "");
		configInput(IN2_INPUT, "");
		configInput(TRIG_INPUT, "");
		configOutput(OUT1_OUTPUT, "");
		configOutput(OUT2_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
        
        outputs[OUT1_OUTPUT].setChannels(inputs[IN1_INPUT].getChannels());
        outputs[OUT1_OUTPUT].writeVoltages(inputs[IN1_INPUT].getVoltages());
	}
};


struct CloudsWidget : ModuleWidget {
	CloudsWidget(Clouds* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/Scope.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<LEDButton>(mm2px(Vec(8.643, 80.603)), module, Clouds::_1X2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(24.897, 80.551)), module, Clouds::GAIN1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(41.147, 80.551)), module, Clouds::GAIN2_PARAM));
		addParam(createParamCentered<LEDButton>(mm2px(Vec(57.397, 80.521)), module, Clouds::TRIG_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(8.643, 96.819)), module, Clouds::TIME_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(24.897, 96.789)), module, Clouds::OFST1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(41.147, 96.815)), module, Clouds::OFST2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(57.397, 96.815)), module, Clouds::THERS_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.643, 113.115)), module, Clouds::IN1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(33.023, 113.115)), module, Clouds::IN2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(57.397, 113.115)), module, Clouds::TRIG_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.833, 113.115)), module, Clouds::OUT1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(45.212, 113.115)), module, Clouds::OUT2_OUTPUT));

		// mm2px(Vec(66.04, 55.88))
		addChild(createWidget<Widget>(mm2px(Vec(0.0, 13.039))));
	}
};


Model* modelClouds = createModel<Clouds, CloudsWidget>("Clouds");
