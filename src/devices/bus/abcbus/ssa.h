// license:BSD-3-Clause
// copyright-holders:Curt Coder
/**********************************************************************

    Luxor ABC-80 Owoco Super Smartaid cartridge emulation

*********************************************************************/

#ifndef MAME_BUS_ABCBUS_SSA_H
#define MAME_BUS_ABCBUS_SSA_H

#pragma once

#include "abcbus.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "machine/nvram.h"
=======
>>>>>>> upstream/master
=======
#include "fileio.h"
>>>>>>> parent of ea6d1ae3f4c (Revert "Remove fileio.h from emu.h")



//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> abc_super_smartaid_device

class abc_super_smartaid_device : public device_t,
						 public device_abcbus_card_interface,
						 public device_nvram_interface
{
public:
	// construction/destruction
	abc_super_smartaid_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	// optional information overrides
	virtual void device_add_mconfig(machine_config &config) override;
	virtual const tiny_rom_entry *device_rom_region() const override;

protected:
	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

	// device_nvram_interface overrides
	virtual void nvram_default() override { }
	virtual bool nvram_read(util::read_stream &file) override { size_t actual; return !file.read(m_nvram, m_nvram.bytes(), actual) && actual == m_nvram.bytes(); }
	virtual bool nvram_write(util::write_stream &file) override { size_t actual; return !file.write(m_nvram, m_nvram.bytes(), actual) && actual == m_nvram.bytes(); }

	// device_abcbus_interface overrides
	virtual void abcbus_cs(uint8_t data) override { m_bus->write_cs(data); }
	virtual uint8_t abcbus_inp() override { return m_bus->read_inp(); }
	virtual void abcbus_out(uint8_t data) override { m_bus->write_out(data); }
	virtual uint8_t abcbus_stat() override { return m_bus->read_stat(); }
	virtual void abcbus_c1(uint8_t data) override { m_bus->write_c1(data); }
	virtual void abcbus_c2(uint8_t data) override { m_bus->write_c2(data); }
	virtual void abcbus_c3(uint8_t data) override { m_bus->write_c3(data); }
	virtual void abcbus_c4(uint8_t data) override { m_bus->write_c4(data); }
	virtual uint8_t abcbus_xmemfl(offs_t offset) override;
	virtual void abcbus_xmemw(offs_t offset, uint8_t data) override;

private:
	required_device<abcbus_slot_device> m_bus;
	required_memory_region m_rom_1;
	required_memory_region m_rom_2;
	required_memory_region m_prom;
	memory_share_creator<uint8_t> m_nvram;
	uint8_t m_rom_bank;
	uint8_t m_prom_bank;
};


// device type definition
DECLARE_DEVICE_TYPE(ABC_SUPER_SMARTAID, abc_super_smartaid_device)

#endif // MAME_BUS_ABCBUS_SSA_H
