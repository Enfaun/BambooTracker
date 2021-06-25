/*
 * Copyright (C) 2021 Rerrah
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <cstdint>
#include "../real_chip_interface.hpp"

namespace scci
{
class SoundInterfaceManager;
class SoundChip;
}

class Scci final : public SimpleRealChipInterface
{
public:
	Scci();
	~Scci() override;
	bool createInstance(RealChipInterfaceGeneratorFunc* f) override;
	RealChipInterfaceType getType() const override { return RealChipInterfaceType::SCCI; }
	bool hasConnected() const override;

	void reset() override;
	void setRegister(uint32_t addr, uint8_t data) override;

private:
	scci::SoundInterfaceManager* man_;
	scci::SoundChip* chip_;
};
